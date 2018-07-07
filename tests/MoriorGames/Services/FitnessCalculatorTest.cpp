
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Services/FitnessCalculator.h"

BOOST_AUTO_TEST_CASE(should_be_able_to_construct_fitness_calculator)
{
    std::string target = "abcdefghij";

    FitnessCalculator fitnessCalculator(target);
}

BOOST_AUTO_TEST_CASE(should_be_able_to_get_1_of_fitness_on_dna)
{
    std::string target = "abcdefghij";
    auto dna = new DNA(target.length());
    dna->setGene(0, 'a');
    dna->setGene(1, 'b');
    dna->setGene(2, 'c');
    dna->setGene(3, 'd');
    dna->setGene(4, 'e');
    dna->setGene(5, 'f');
    dna->setGene(6, 'g');
    dna->setGene(7, 'h');
    dna->setGene(8, 'i');
    dna->setGene(9, 'j');

    FitnessCalculator fitnessCalculator(target);
    auto fitness = fitnessCalculator.calculate(dna);

    BOOST_CHECK_EQUAL(1, fitness);
}

BOOST_AUTO_TEST_CASE(should_be_able_to_get_0_3_of_fitness_on_dna)
{
    std::string target = "abcdefghij";
    auto dna = new DNA(target.length());
    dna->setGene(0, 'a');
    dna->setGene(1, 'x');
    dna->setGene(2, 'x');
    dna->setGene(3, 'x');
    dna->setGene(4, 'e');
    dna->setGene(5, 'x');
    dna->setGene(6, 'x');
    dna->setGene(7, 'x');
    dna->setGene(8, 'i');
    dna->setGene(9, 'x');

    FitnessCalculator fitnessCalculator(target);
    auto fitness = fitnessCalculator.calculate(dna);

    BOOST_CHECK_EQUAL(.3, fitness);
}

BOOST_AUTO_TEST_CASE(should_be_able_to_get_full_fitness_on_dna)
{
    std::string target = "You know nothing, Jon Snow";
    auto dna = new DNA(target.length());
    dna->setGene(0, 'Y');
    dna->setGene(1, 'o');
    dna->setGene(2, 'u');
    dna->setGene(3, ' ');
    dna->setGene(4, 'k');
    dna->setGene(5, 'n');
    dna->setGene(6, 'o');
    dna->setGene(7, 'w');
    dna->setGene(8, ' ');
    dna->setGene(9, 'n');
    dna->setGene(10, 'o');
    dna->setGene(11, 't');
    dna->setGene(12, 'h');
    dna->setGene(13, 'i');
    dna->setGene(14, 'n');
    dna->setGene(15, 'g');
    dna->setGene(16, ',');
    dna->setGene(17, ' ');
    dna->setGene(18, 'J');
    dna->setGene(19, 'o');
    dna->setGene(20, 'n');
    dna->setGene(21, ' ');
    dna->setGene(22, 'S');
    dna->setGene(23, 'n');
    dna->setGene(24, 'o');
    dna->setGene(25, 'w');

    FitnessCalculator fitnessCalculator(target);
    auto fitness = fitnessCalculator.calculate(dna);

    BOOST_CHECK_EQUAL(1, fitness);
}

BOOST_AUTO_TEST_CASE(should_be_able_to_get_half_fitness_on_dna)
{
    std::string target = "You know nothing, Jon Snow";
    auto dna = new DNA(target.length());
    dna->setGene(0, 'Y');
    dna->setGene(1, 'x');
    dna->setGene(2, 'u');
    dna->setGene(3, 'x');
    dna->setGene(4, 'k');
    dna->setGene(5, 'x');
    dna->setGene(6, 'o');
    dna->setGene(7, 'x');
    dna->setGene(8, ' ');
    dna->setGene(9, 'x');
    dna->setGene(10, 'o');
    dna->setGene(11, 'x');
    dna->setGene(12, 'h');
    dna->setGene(13, 'x');
    dna->setGene(14, 'n');
    dna->setGene(15, 'x');
    dna->setGene(16, ',');
    dna->setGene(17, 'x');
    dna->setGene(18, 'J');
    dna->setGene(19, 'x');
    dna->setGene(20, 'n');
    dna->setGene(21, 'x');
    dna->setGene(22, 'S');
    dna->setGene(23, 'x');
    dna->setGene(24, 'o');
    dna->setGene(25, 'x');

    FitnessCalculator fitnessCalculator(target);
    auto fitness = fitnessCalculator.calculate(dna);

    BOOST_CHECK_EQUAL(.5, fitness);
}
