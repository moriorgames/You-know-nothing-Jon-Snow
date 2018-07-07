#ifndef MORIOR_GAMES_MUTATOR_H
#define MORIOR_GAMES_MUTATOR_H

#include <vector>
#include <string>
#include "../DTO/DNA.h"

class Mutator
{
public:
    explicit Mutator() = default;
    void mutate(DNA &dna, int mutationRate);

private:
    char getRandomChar();
};

#endif
