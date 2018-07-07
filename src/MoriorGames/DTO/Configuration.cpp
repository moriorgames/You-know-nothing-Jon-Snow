#include "Configuration.h"

Configuration::Configuration(std::string target, int population, int maxGenerations, int mutationRate)
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

int Configuration::getMutationRate() const
{
    return mutationRate;
}

void Configuration::print()
{
    printf("========= Configuration: \n"
           " - target %s\n"
           " - population %i\n"
           " - maxGenerations %i\n"
           " - mutationRate %i\n"
           " \n",
           target.c_str(),
           population,
           maxGenerations,
           mutationRate
    );
}
