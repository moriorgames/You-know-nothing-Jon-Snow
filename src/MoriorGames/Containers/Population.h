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
    Configuration *configuration;
    FitnessCalculator fitnessCalculator;
};

#endif
