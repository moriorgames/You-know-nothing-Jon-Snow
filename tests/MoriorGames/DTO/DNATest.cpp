
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/DTO/DNA.h"

BOOST_AUTO_TEST_CASE(should_be_able_to_initialize_genes_given_a_string_length)
{
    int length = 10;
    auto dna = new DNA(length);

    BOOST_CHECK_EQUAL(length, dna->getPhrase().length());
}

BOOST_AUTO_TEST_CASE(should_be_able_to_edit_gene_value)
{
    auto dna = new DNA(3);
    dna->setGene(0, 'a');
    dna->setGene(1, 'b');
    dna->setGene(2, 'c');

    BOOST_CHECK_EQUAL("abc", dna->getPhrase());
}
