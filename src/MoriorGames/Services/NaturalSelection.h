#ifndef MORIOR_GAMES_NaturalSelection_H
#define MORIOR_GAMES_NaturalSelection_H

#include "../DTO/DNA.h"

class NaturalSelection
{
public:
    void execute(std::vector<DNA *> dnas, int population);

private:
    std::vector<int> matingPool;
};

#endif
