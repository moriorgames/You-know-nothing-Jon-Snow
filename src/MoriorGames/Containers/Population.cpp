#include "Population.h"
#include "../Services/Mutator.h"
#include "../Services/NaturalSelection.h"
#include <string>

Population::Population(Configuration *configuration)
    : fitnessCalculator(configuration->getTarget()), configuration{configuration}
{
    Mutator mutator;
    // Initialize
    for (int i = 0; i < configuration->getPopulation(); ++i) {
        auto dna = new DNA(configuration->getTarget().length());
        dnas.push_back(dna);
        mutator.mutate(dna, 100);
    }
}

void Population::process()
{
    NaturalSelection naturalSelection;

    for (int generation = 0; generation < configuration->getMaxGenerations(); ++generation) {
        printf("==: Generation %i\n", generation);
        // Calculate fitness
        for (auto dna:dnas) {
            auto fitness = fitnessCalculator.calculate(dna);
            dna->setFitness(fitness);
            printf("- Gen: %s Fitness: %f\n", dna->getPhrase().c_str(), fitness);
        }
        printf("    After Selection :==\n");

        // Natural selection
        naturalSelection.execute(dnas, configuration->getPopulation());
        for (auto dna:dnas) {
            auto fitness = fitnessCalculator.calculate(dna);
            dna->setFitness(fitness);
            printf("- Gen: %s Fitness: %f\n", dna->getPhrase().c_str(), fitness);
        }

        // Next Generation

    }
}
