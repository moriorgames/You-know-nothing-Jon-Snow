#ifndef MORIOR_GAMES_NaturalSelection_H
#define MORIOR_GAMES_NaturalSelection_H

#include "../DTO/Configuration.h"
#include "../DTO/DNA.h"

class NaturalSelection
{
public:
    const int BEST_DISPLAY = 10;

    std::vector<DNA *> execute(std::vector<DNA *> dnas, Configuration *);

private:
    std::vector<int> matingPool;
};

#endif
