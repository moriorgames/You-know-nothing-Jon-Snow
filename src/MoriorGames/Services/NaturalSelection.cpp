#include "NaturalSelection.h"
#include "Randomizer.h"
#include <cmath>

std::vector<DNA *> NaturalSelection::execute(std::vector<DNA *> dnas, Configuration *config)
{
    int geneticSize = config->getTarget().size();
    std::vector<DNA *> newGeneration;

    // Create the mating pool from fitness dna
    for (int index = 0; index < dnas.size(); ++index) {
        int matingPoolRatio = ceil(config->getPopulation() * dnas[index]->getFitness());
        for (int i = 0; i < matingPoolRatio; ++i) {
            matingPool.push_back(index);
        }
    }

    std::random_shuffle(matingPool.begin(), matingPool.end());

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
