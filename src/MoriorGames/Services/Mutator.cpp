#include "Mutator.h"
#include <random>

void Mutator::mutate(DNA &dna, int mutationRate)
{
    for (int i = 0; i < dna.getGenes().size(); ++i) {
        if (mutationRate >= 100) {
            dna.setGene(i, getRandomChar());
        } else {
            auto mutation = rand() % 100;
            if (mutation <= mutationRate) {
                dna.setGene(i, getRandomChar());
            }
        }
    }
}
char Mutator::getRandomChar()
{
    char ALLOWED_CHARS[] = "abcdefghijklmnomprstuvwxyz ABCDEFGHIJKLMNOMPRSTUVWXYZ,.;";

//    return ALLOWED_CHARS[rand() % strlen(ALLOWED_CHARS)];
    return 'j';
}
