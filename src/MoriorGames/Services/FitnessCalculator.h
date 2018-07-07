#ifndef MORIOR_GAMES_FITNESS_CALCULATOR_H
#define MORIOR_GAMES_FITNESS_CALCULATOR_H

#include <vector>
#include <string>
#include "../DTO/DNA.h"

class FitnessCalculator
{
public:
    explicit FitnessCalculator(std::string target);
    double calculate(DNA *dna);

private:
    std::vector<char> target;

};

#endif
