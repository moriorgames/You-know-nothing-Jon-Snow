#include "Population.h"
#include "../Services/Mutator.h"
#include <string>

Population::Population(Configuration *config)
    : fitnessCalculator(config->getTarget()),
      maxGenerations{config->getMaxGenerations()},
      mutationRate{config->getMutationRate()}
{
    Mutator mutator;
    // Initialize
    for (int i = 0; i < config->getPopulation(); ++i) {
        auto dna = new DNA(config->getTarget().length());
        dnas.push_back(dna);
        mutator.mutate(dna, 100);
    }
}

void Population::process()
{
    for (int generation = 0; generation < maxGenerations; ++generation) {
        printf("==: Generation %i :==\n", generation);
        // Calculate fitness
        for (auto dna:dnas) {
            auto fitness = fitnessCalculator.calculate(dna);
            printf("- Gen: %s Fitness: %f\n", dna->getPhrase().c_str(), fitness);
        }

        // Natural selection

        // Next Generation

    }
}
