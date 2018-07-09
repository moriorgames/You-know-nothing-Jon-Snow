#include "Configuration.h"

Configuration::Configuration(
    std::string target,
    int population,
    int maxGenerations,
    int mutationRate,
    int reproduction,
    int extinction,
    int environment
)
    : target{target},
      population{population},
      maxGenerations{maxGenerations},
      mutationRate{mutationRate},
      reproduction{reproduction},
      extinction{extinction},
      environment{environment}
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

int Configuration::getReproduction() const
{
    return reproduction;
}

int Configuration::getExtinction() const
{
    return extinction;
}

int Configuration::getEnvironment() const
{
    return environment;
}

void Configuration::print()
{
    printf("========= Configuration: \n"
           " - target %s\n"
           " - population %i\n"
           " - maxGenerations %i\n"
           " - mutationRate %i\n"
           " - reproduction %i\n"
           " - extinction %i\n"
           " - environment %i\n"
           " \n",
           target.c_str(),
           population,
           maxGenerations,
           mutationRate,
           reproduction,
           extinction,
           environment
    );
}
