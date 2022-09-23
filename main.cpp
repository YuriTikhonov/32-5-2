#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <clocale>
#include "nlohmann_json/include/nlohmann/json.hpp"

struct Movie
{
    std::string movieTitle;
    std::string country;
    std::string productionDate;
    std::string company;
    std::string scriptAuthor;
    std::string director;
    std::string producer;
    std::unordered_map<std::string,std::string>actors;
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::vector<Movie> movie(5);
    std::ofstream file("movie.json");
    nlohmann::json dict = {
            {"movie title",movie[0].movieTitle = "Место встречи изменить нельзя"},
            {"country",movie[0].country = "СССР"},
            {"productionDate",movie[0].productionDate = "1979"},
            {"company",movie[0].company = "Одесская киностудия"},
            {"scriptAuthor",movie[0].scriptAuthor = "Станислав Говорухин"},
            {"Actors:", movie[0].actors = {{"Глеб Жеглов",    "Владимир Высоцкий"},
                                        {"Володя Шарапов", "Владимир Конкин"},
                                        {"Груздев",        "Сергей Юрский"},
                                        {"Пётр Ручников",  "Евгений Евстигнеев"},
                                        {"Манька Облигация","Лариса Удовиченко"}
            }
            }
    };
    file << dict;

    return 0;
}