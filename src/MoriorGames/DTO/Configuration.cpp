#include "Configuration.h"

Configuration::Configuration(std::string target, int population, int maxGenerations, double mutationRate)
    : target{target}, population{population}, maxGenerations{maxGenerations}, mutationRate{mutationRate}
{
}

const std::string &Configuration::getTarget() const
{
    return target;
}

int Configuration::getPopulation() const
{
    return population;
}

int Configuration::getMaxGenerations() const
{
    return maxGenerations;
}

double Configuration::getMutationRate() const
{
    return mutationRate;
}

void Configuration::print()
{

}
