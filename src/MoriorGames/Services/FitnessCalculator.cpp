#include "FitnessCalculator.h"

FitnessCalculator::FitnessCalculator(std::string target)
{
    std::vector<char> data(target.begin(), target.end());
    this->target = data;
}

double FitnessCalculator::calculate(DNA dna)
{
    auto genes = dna.getGenes();
    int matches = 0;
    for (int i = 0; i < genes.size(); ++i) {
        if (genes[i] == target[i]) {
            matches++;
        }
    }

    return matches / (double)genes.size();
}
