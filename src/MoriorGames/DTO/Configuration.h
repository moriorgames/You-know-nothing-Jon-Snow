#ifndef MORIOR_GAMES_CONFIGURATION_H
#define MORIOR_GAMES_CONFIGURATION_H

#include <string>

class Configuration
{
public:
    Configuration(std::string target, int population, int maxGenerations, int mutationRate);
    const std::string &getTarget() const;
    int getPopulation() const;
    int getMaxGenerations() const;
    int getMutationRate() const;
    void print();

private:
    std::string target;
    int population;
    int maxGenerations;
    int mutationRate;
};

#endif
