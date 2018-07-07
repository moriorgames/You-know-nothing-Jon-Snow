#include "NaturalSelection.h"
#include "Randomizer.h"

void NaturalSelection::execute(std::vector<DNA *> dnas, int population)
{
    matingPool.clear();
    // Create the mating pool from fitness dnas

    for (int index = 0; index < dnas.size(); ++index) {
        int matingPoolRatio = population * dnas[index]->getFitness();
        for (int i = 0; i < matingPoolRatio; ++i) {
            matingPool.push_back(index);
        }
    }

    int geneticSize = dnas[0]->getGenes().size();

    for (int index = 0; index < population; ++index) {
        // Pick 2 parents and update a child
        int father = Randomizer::randomize(0, matingPool.size() - 1);
        int mother = Randomizer::randomize(0, matingPool.size() - 1);
        for (int i = 0; i < geneticSize; ++i) {
            char gen;
            if (i % 2 == 0) {
                gen = dnas[matingPool[father]]->getGenes()[i];
            } else {
                gen = dnas[matingPool[mother]]->getGenes()[i];
            }
            dnas[index]->setGene(i, gen);
        }
        if (index < population / 5) {
            printf("- Gen: %s Fitness: %f\n", dnas[index]->getPhrase().c_str(), dnas[index]->getFitness());
        }
    }
}
