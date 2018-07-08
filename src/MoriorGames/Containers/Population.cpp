#include "Population.h"
#include "../Services/Randomizer.h"
#include <cmath>
#include <string>
#include <ctime>

Population::Population(Configuration *configuration)
    : fitnessCalculator(configuration->getTarget()), config{configuration}
{
    mutator = new Mutator;
}

void Population::process()
{
    clock_t begin = clock();

    initialize();

    for (int generation = 0; generation < config->getMaxGenerations(); ++generation) {

        printf("==: Generation %i Population %lu\n", generation, dnas.size());

        calculateFitness();

        // Evaluate
        for (auto dna:dnas) {
            if (dna->getFitness() >= 0.98) {
                printf("==== We found the perfect solution at Generation %i==\n", generation);
                generation = config->getMaxGenerations();
                dna->print();
                break;
            }
        }

        environmentExtinction();

        printBest();

        newGeneration();
    }

    clock_t end = clock();
    double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    printf("\nElapsed time %f\n", elapsedTime);
}

void Population::initialize()
{
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
    for (int i = 0; i < 20; ++i) {
        dnas[i]->print();
    }
}
