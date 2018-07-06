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
            getDouble(document, "mutationRate")
        );
    }

    return nullptr;
}
