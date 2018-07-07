#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdio>

#include "src/MoriorGames/Parsers/FileParser.h"
#include "src/MoriorGames/Containers/Population.h"

int main()
{
    std::string file = "data/parameters.json";
    std::ifstream parameters(file.c_str());
    std::stringstream bufferParameters;
    bufferParameters << parameters.rdbuf();
    std::string json = bufferParameters.str();

    auto parser = new FileParser(json);
    auto config = parser->parse();
    Population population(config);
    population.process();

    return 0;
}
