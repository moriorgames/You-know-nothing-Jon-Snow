#ifndef MORIOR_GAMES_CONFIGURATION_H
#define MORIOR_GAMES_CONFIGURATION_H

#include <string>

class Configuration
{
public:
    Configuration(std::string target, int population, int maxGenerations, double mutationRate);
    const std::string &getTarget() const;
    int getPopulation() const;
    int getMaxGenerations() const;
    double getMutationRate() const;
    void print();

private:
    std::string target;
    int population;
    int maxGenerations;
    double mutationRate;
};

#endif
