#ifndef MORIOR_GAMES_CONFIGURATION_H
#define MORIOR_GAMES_CONFIGURATION_H

#include <string>

class Configuration
{
public:
    Configuration(
        std::string target,
        int population,
        int maxGenerations,
        int mutationRate,
        int reproduction,
        int extinction,
        int environment
    );
    const std::string &getTarget() const;
    int getPopulation() const;
    int getMaxGenerations() const;
    int getMutationRate() const;
    int getReproduction() const;
    int getExtinction() const;
    int getEnvironment() const;
    void print();

private:
    std::string target;
    int population;
    int maxGenerations;
    int mutationRate;
    int reproduction;
    int extinction;
    int environment;
};

#endif
