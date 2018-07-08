#ifndef MORIOR_GAMES_POPULATION_H
#define MORIOR_GAMES_POPULATION_H

#include <vector>
#include <string>
#include "../DTO/Configuration.h"
#include "../DTO/DNA.h"
#include "../Services/FitnessCalculator.h"
#include "../Services/Mutator.h"

class Population
{
public:
    explicit Population(Configuration *);
    void process();

private:
    std::vector<DNA *> dnas;
    Configuration *config;
    FitnessCalculator fitnessCalculator;
    Mutator *mutator;

    void initialize();
    void calculateFitness();
    void sortByFitness();
    void environmentExtinction();
    void newGeneration();
    std::vector<int> matingPoolCreator();

    void printBest();
};

#endif
