#ifndef MORIOR_GAMES_FITNESS_CALCULATOR_H
#define MORIOR_GAMES_FITNESS_CALCULATOR_H

#include <vector>
#include <string>
#include "../DTO/DNA.h"

class FitnessCalculator
{
public:
    FitnessCalculator(std::string target);
    double calculate(DNA *);

private:
    std::vector<char> target;

};

#endif
