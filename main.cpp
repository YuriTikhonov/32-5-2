#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann_json/include/nlohmann/json.hpp"
using nlohmann::json;

int main()
{
    std::vector <json> alljSon;
    std::ifstream i("movie.json");
    json j = json::parse(i);
    for (auto it = j.begin(); it != j.end(); ++it)
    {
        if (j.is_array())
        {
            alljSon.push_back(it.value());
        }
        else
        {
            // If it's not an array, it's an object, and from what I understood you want the key too.
            alljSon.push_back({it.key(), it.value()});
        }
    }
    std::cout << alljSon << " ";
    return 0;
}