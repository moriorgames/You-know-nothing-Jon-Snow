#include "FileParser.h"

FileParser::FileParser(std::string json)
    : JsonParser(json)
{
}

Configuration *FileParser::parse()
{
    if (document.IsObject()) {

        return new Configuration(
            getString(document, "target"),
            getInt(document, "population"),
            getInt(document, "maxGenerations"),
            getInt(document, "mutationRate")
        );
    }

    return nullptr;
}
