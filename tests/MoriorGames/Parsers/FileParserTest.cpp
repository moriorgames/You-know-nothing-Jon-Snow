
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Parsers/FileParser.h"

BOOST_AUTO_TEST_CASE(should_be_able_to_return_instance_of_configuration_from_json_file)
{
    std::string json = R"({"target": "parser", "population": 1, "maxGenerations": 2, "mutationRate": 0.1})";

    auto parser = new FileParser(json);
    auto configuration = parser->parse();

    BOOST_CHECK_EQUAL("parser", configuration->getTarget());
}
