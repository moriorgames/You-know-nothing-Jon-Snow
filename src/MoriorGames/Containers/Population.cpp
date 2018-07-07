#include "Population.h"

Population::Population(Configuration *config)
    : fitnessCalculator(config->getTarget()),
      Kpopulation{config->getPopulation()},
      maxGenerations{config->getMaxGenerations()},
      mutationRate{config->getMutationRate()}
{
}
