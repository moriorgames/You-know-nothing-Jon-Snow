#include "Population.h"
#include "../Services/Mutator.h"
#include "../Services/Randomizer.h"
#include <cmath>
#include <string>
#include <ctime>

Population::Population(Configuration *configuration)
    : fitnessCalculator(configuration->getTarget()), config{configuration}
{
}

void Population::process()
{
    clock_t begin = clock();

    Mutator mutator;

    std::vector<DNA *> dnas;
    // Initialize
    for (int i = 0; i < config->getPopulation(); ++i) {
        auto dna = new DNA(config->getTarget().length());
        dnas.push_back(dna);
        // Full random
        mutator.mutate(dna, 100);
    }

    for (int generation = 0; generation < config->getMaxGenerations(); ++generation) {

        printf("==: Generation %i Population %lu\n", generation, dnas.size());
        // Calculate fitness
        for (auto dna:dnas) {
            dna->setFitness(fitnessCalculator.calculate(dna));
//            dna->print();
        }

        auto matingPool = matingPoolCreator(dnas);
        dnas = newGeneration(dnas, matingPool);

        // Evaluate
        for (auto dna:dnas) {
            mutator.mutate(dna, config->getMutationRate());
            auto fitness = fitnessCalculator.calculate(dna);
            dna->setFitness(fitness);
            dna->print();
            if (fitness == 1) {
                printf("==== We found the perfect solution at Generation %i==\n", generation);
                generation = config->getMaxGenerations();
                dna->print();
                break;
            }
        }
    }

    clock_t end = clock();
    double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    printf("\nElapsed time %f\n", elapsedTime);
}

std::vector<int> Population::matingPoolCreator(std::vector<DNA *> dnas)
{
    std::vector<int> matingPool;

    // Create the mating pool from fitness dna
    for (int index = 0; index < dnas.size(); ++index) {
        int matingPoolRatio = ceil(config->getPopulation() * dnas[index]->getFitness());
        for (int i = 0; i < matingPoolRatio; ++i) {
            matingPool.push_back(index);
        }
    }
    std::random_shuffle(matingPool.begin(), matingPool.end());

    return matingPool;
}

std::vector<DNA *> Population::newGeneration(std::vector<DNA *> dnas, std::vector<int> matingPool)
{
    int geneticSize = config->getTarget().size();
    std::vector<DNA *> newGeneration;

    bool hasChild = false;
    int father = 0;
    int mother = 0;
    for (int k = 0; k < matingPool.size(); ++k) {
        if (k <= config->getEnvironment()) {
            if (hasChild) {
                mother = matingPool[k];

                // Each couple has between 1 and 3 child
                for (int j = 0; j < Randomizer::randomize(1, config->getReproduction()); ++j) {
                    // Pick 2 parents and update a child
                    auto child = new DNA(geneticSize);
                    for (int i = 0; i < geneticSize; ++i) {
                        char gen;
                        if (j % 2 == 0) {
                            if (i % 2 == 0) {
                                gen = dnas[father]->getGenes()[i];
                            } else {
                                gen = dnas[mother]->getGenes()[i];
                            }
                        } else {
                            if (i % 2 == 0) {
                                gen = dnas[mother]->getGenes()[i];
                            } else {
                                gen = dnas[father]->getGenes()[i];
                            }
                        }
                        child->setGene(i, gen);
                    }
                    newGeneration.push_back(child);
                }

                hasChild = false;
            } else {
                father = matingPool[k];
                hasChild = true;
            }
        }
    }

    dnas.clear();
    matingPool.clear();

    return newGeneration;
}
