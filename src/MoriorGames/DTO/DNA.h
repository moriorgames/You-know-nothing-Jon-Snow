#ifndef MORIOR_GAMES_DNA_H
#define MORIOR_GAMES_DNA_H

#include <vector>
#include <string>

class DNA
{
public:
    explicit DNA(int length);
    void setGene(int index, char value);
    std::string getPhrase();

private:
    std::vector<char> genes;
};

#endif
