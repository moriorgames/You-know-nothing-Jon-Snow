
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/DTO/Configuration.h"

BOOST_AUTO_TEST_CASE(should_be_able_to_create_configuration_dto_and_access_its_data)
{
    std::string target = "Hello world";
    int population = 10;
    int maxGenerations = 20;
    double mutationRate = .12;
    auto configuration = new Configuration(target, population, maxGenerations, mutationRate);

    BOOST_CHECK_EQUAL(target, configuration->getTarget());
    BOOST_CHECK_EQUAL(population, configuration->getPopulation());
    BOOST_CHECK_EQUAL(maxGenerations, configuration->getMaxGenerations());
    BOOST_CHECK_EQUAL(mutationRate, configuration->getMutationRate());
}
