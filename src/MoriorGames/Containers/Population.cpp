#include "Population.h"

Population::Population(Configuration *config)
    : target{config->getTarget()}, populationQuantity{config->getPopulation()},
      maxGenerations{config->getMaxGenerations()}, mutationRate{config->getMutationRate()}
{
}
