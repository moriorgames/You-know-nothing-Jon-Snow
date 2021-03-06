#ifndef MORIOR_GAMES_JSON_PARSER_H
#define MORIOR_GAMES_JSON_PARSER_H

#include <string>
#include <vector>
#include "../../../lib/rapidjson/document.h"

using namespace rapidjson;

class JsonParser
{
public:
    JsonParser(std::string json);

protected:
    Document document;
    int getInt(const rapidjson::Value &data, std::string key);
    long int getInt64(const rapidjson::Value &data, std::string key);
    double getDouble(const rapidjson::Value &data, std::string key);
    std::string getString(const rapidjson::Value &data, std::string key);
    bool getBool(const rapidjson::Value &data, std::string key);
};

#endif
