
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Containers/Population.h"

BOOST_AUTO_TEST_CASE(should_be_able_to_instantiate_population_container)
{
    std::string target = "Hello world";
    int populationQ = 10;
    int maxGenerations = 20;
    double mutationRate = .12;
    auto population = new Population(new Configuration(target, populationQ, maxGenerations, mutationRate));
}
