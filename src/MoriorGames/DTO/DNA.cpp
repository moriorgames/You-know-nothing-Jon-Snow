#include "DNA.h"

DNA::DNA(int length)
{
    for (int i = 0; i < length; ++i) {
        genes.push_back(' ');
    }
}

void DNA::setGene(int index, char value)
{
    genes[index] = value;
}

const std::vector<char> &DNA::getGenes() const
{
    return genes;
}

std::string DNA::getPhrase()
{
    std::string phrase(genes.begin(), genes.end());

    return phrase;
}
