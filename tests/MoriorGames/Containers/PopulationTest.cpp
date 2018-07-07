
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Containers/Population.h"

BOOST_AUTO_TEST_CASE(should_be_able_to_instantiate_population_container)
{
    std::string target = "Hello world";
    Population population(new Configuration(target, 500, 100, 12, 2, 100));
}
