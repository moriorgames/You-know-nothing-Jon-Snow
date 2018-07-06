#ifndef MORIOR_GAMES_FILE_PARSER_H
#define MORIOR_GAMES_FILE_PARSER_H

#include "../DTO/Configuration.h"
#include "JsonParser.h"

class FileParser: public JsonParser
{
public:
    explicit FileParser(std::string json);
    Configuration *parse();

};

#endif
