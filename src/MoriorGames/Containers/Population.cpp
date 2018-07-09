#include "Population.h"
#include "../Services/Randomizer.h"
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>

Population::Population(Configuration *configuration)
    : fitnessCalculator(configuration->getTarget()), config{configuration}
{
    mutator = new Mutator;
}

void Population::process()
{
    clock_t begin = clock();

    initialize();

    std::ofstream logFile(logFileName, std::ios_base::out | std::ios_base::app);
    for (int generation = 0; generation < config->getMaxGenerations(); ++generation) {

        printf("==: Generation %i Population %lu\n", generation, dnas.size());
        logFile << "==: Generation " << generation << " Population: " << dnas.size() << std::endl;

        calculateFitness();

        generation = evaluate(generation);

        environmentExtinction();

        printBest();

        newGeneration();
    }

    clock_t end = clock();
    double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    printf("\nElapsed time %f\n", elapsedTime);
    logFile << "Elapsed time " << elapsedTime << std::endl;
}

void Population::initialize()
{
    logFileName = "data/log" + std::to_string(long(std::time(nullptr))) + ".txt";
    for (int i = 0; i < config->getPopulation(); ++i) {
        auto dna = new DNA(config->getTarget().length());
        dnas.push_back(dna);
        // Full random
        mutator->mutate(dna, 100);
    }
}

void Population::calculateFitness()
{
    for (auto dna:dnas) {
        dna->setFitness(fitnessCalculator.calculate(dna));
    }
    sortByFitness();
}

void Population::sortByFitness()
{
    std::sort(dnas.begin(), dnas.end(), [](const DNA *a, const DNA *b) -> bool
    {
        return a->getFitness() > b->getFitness();
    });
}

void Population::environmentExtinction()
{
    int size = dnas.size();
    int extincion = ceil(config->getEnvironment() * 0.01 * size);
    dnas.resize(size - extincion);
}

void Population::newGeneration()
{
    std::vector<int> matingPool = matingPoolCreator();
    int geneticSize = config->getTarget().size();
    std::vector<DNA *> newGeneration;

    for (int i = 0; i < config->getPopulation(); ++i) {
        int father = Randomizer::randomize(0, matingPool.size() - 1);
        int mother = Randomizer::randomize(0, matingPool.size() - 1);

        // Each couple has between N child
        for (int j = 1; j <= 2; ++j) {
            // Pick 2 parents and update a child
            auto child = new DNA(geneticSize);
            bool odd = true;
            for (int k = 0; k < geneticSize; ++k) {
                char gen;
                if (j % 2 == 0) {
                    if (odd) {
                        gen = dnas[matingPool[father]]->getGenes()[k];
                        odd = false;
                    } else {
                        gen = dnas[matingPool[mother]]->getGenes()[k];
                        odd = true;
                    }
                } else {
                    if (!odd) {
                        gen = dnas[matingPool[father]]->getGenes()[k];
                        odd = true;
                    } else {
                        gen = dnas[matingPool[mother]]->getGenes()[k];
                        odd = false;
                    }
                }
                child->setGene(k, gen);
            }
            mutator->mutate(child, config->getMutationRate());
            newGeneration.push_back(child);
        }
    }

    matingPool.clear();
    dnas.clear();
    dnas = newGeneration;
}

std::vector<int> Population::matingPoolCreator()
{
    std::vector<int> matingPool;

    for (int index = 0; index < dnas.size(); ++index) {
        int matingPoolRatio = config->getEnvironment() * dnas[index]->getFitness();
        for (int i = 0; i < matingPoolRatio; ++i) {
            matingPool.push_back(index);
        }
    }

    return matingPool;
}

void Population::printBest()
{
    std::ofstream logFile(logFileName, std::ios_base::out | std::ios_base::app);

    for (int i = 0; i < 10; ++i) {
        dnas[i]->print();
        logFile << "Genes: " << dnas[i]->getPhrase() << " Fitness: " << dnas[i]->getFitness() << std::endl;
    }
}

int Population::evaluate(int generation)
{
    // Evaluate
    for (auto dna:dnas) {
        if (dna->getFitness() == 1) {
            printf("==== We found the perfect solution at Generation %i ==\n", generation);
            generation = config->getMaxGenerations();
            dna->print();
            break;
        }
    }

    return generation;
}
