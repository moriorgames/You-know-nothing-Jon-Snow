#include "Mutator.h"
#include "Randomizer.h"

void Mutator::mutate(DNA *dna, int mutationRate)
{
    for (int i = 0; i < dna->getGenes().size(); ++i) {
        if (mutationRate >= 100) {
            dna->setGene(i, getRandomChar());
        } else {
            auto mutation = Randomizer::randomize(0, 100);
            if (mutation <= mutationRate) {
                dna->setGene(i, getRandomChar());
            }
        }
    }
}
char Mutator::getRandomChar()
{
//    char ALLOWED_CHARS[] = "abcdefghijklmnomprstuvwxyz ABCDEFGHIJKLMNOMPRSTUVWXYZ,.;";
    char ALLOWED_CHARS[] = "abcdefghijklmnomprstuvwxyz";

    return ALLOWED_CHARS[Randomizer::randomize(0, strlen(ALLOWED_CHARS) - 1)];
}
