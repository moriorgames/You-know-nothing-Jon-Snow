#ifndef MORIOR_GAMES_POPULATION_H
#define MORIOR_GAMES_POPULATION_H

#include <vector>
#include <string>
#include "../DTO/Configuration.h"
#include "../DTO/DNA.h"
#include "../Services/FitnessCalculator.h"

class Population
{
public:
    explicit Population(Configuration *);
    void process();

private:
    int maxGenerations;
    double mutationRate;

    FitnessCalculator fitnessCalculator;
    bool finished = false;
    int generations = 0;
    std::string bestTarget = "";
    std::vector<DNA > dnas;

    void initialize();
};

#endif
