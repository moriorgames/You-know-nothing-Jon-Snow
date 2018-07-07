#include "Population.h"
#include "../Services/Mutator.h"
#include "../Services/NaturalSelection.h"
#include <string>
#include <ctime>

Population::Population(Configuration *configuration)
    : fitnessCalculator(configuration->getTarget()), configuration{configuration}
{
    Mutator mutator;
    // Initialize
    for (int i = 0; i < configuration->getPopulation(); ++i) {
        auto dna = new DNA(configuration->getTarget().length());
        dnas.push_back(dna);
        // Full random
        mutator.mutate(dna, 100);
    }
}

void Population::process()
{
    clock_t begin = clock();

    Mutator mutator;
    NaturalSelection naturalSelection;

    for (int generation = 0; generation < configuration->getMaxGenerations(); ++generation) {

        printf("==: Generation %i\n", generation);
        // Calculate fitness
        for (auto dna:dnas) {
            dna->setFitness(fitnessCalculator.calculate(dna));
        }

        // Natural selection
        naturalSelection.execute(dnas, configuration->getPopulation());
        for (auto dna:dnas) {
            mutator.mutate(dna, configuration->getMutationRate());
            auto fitness = fitnessCalculator.calculate(dna);
            dna->setFitness(fitness);
            if (fitness == 1) {
                printf("==== We found the perfect solution at Generation %i==\n", generation);
                generation = configuration->getMaxGenerations();
                break;
            }
        }

        // Next Generation
    }

    clock_t end = clock();
    double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    printf("\nElapsed time %f\n", elapsedTime);
}
