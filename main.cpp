#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <clocale>
#include "nlohmann_json/include/nlohmann/json.hpp"

struct MovieName
{
    std::string movieTitle;
}m1,m2;

struct Movie
{
    //std::string movieTitle;
    std::string country;
    std::string productionDate;
    std::string company;
    std::string scriptAuthor;
    std::string director;
    //std::string producer;
    std::unordered_map<std::string,std::string>actors;
}movie1,movie2;//,movie3,movie4,movie5;

int main()
{
    setlocale(LC_CTYPE, "rus");
    //std::vector<Movie> movie(2);

    std::ofstream file("movie.json");
    //nlohmann::json data = {MovieName.mo,Movie};
    nlohmann::json dict = nlohmann::json::array();
    m1 = {"Место встречи изменить нельзя"};
    m2 = {"Белое солнце пустыни"};

    movie1 = {
            //{"movie title",movie1.movieTitle = "Место встречи изменить нельзя"},
            {movie1.country = "СССР"},
            {movie1.productionDate = "1979"},
            {movie1.company = "Одесская киностудия"},
            {movie1.scriptAuthor = "Станислав Говорухин"},
            {movie1.director = "Станислав Говорухин"},
            { movie1.actors = {{"Глеб Жеглов",    "Владимир Высоцкий"},
                                        {"Володя Шарапов", "Владимир Конкин"},
                                        {"Груздев",        "Сергей Юрский"},
                                        {"Пётр Ручников",  "Евгений Евстигнеев"},
                                        {"Манька Облигация","Лариса Удовиченко"}
            }
            }

    };

     movie2 = {
            //{"movie title",movie2.movieTitle = "Белое солнце пустыни"},
            {movie2.country = "СССР"},
            {movie2.productionDate = "1969"},
            {movie2.company = "Мосфильм, Ленфильм"},
            {movie2.scriptAuthor = "Валентин Ежов\n"
                                                  "Рустам Ибрагимбеков\n"
                                                  "Марк Захаров"},
            {movie2.director = "Владимир Мотыль"},
            {movie2.actors = {{"Фёдор Сухов",    "Анатолий Кузнецов"},
                                           {"Саид", "Спартак Мишулин"},
                                           {"Абдулла",        "Кахи Кавсадзе"},
                                           {"Верещагин",  "Павел Луспекаев"},
                                           {"Гюльчатай","Татьяна Федотова"},
                                         {"Петруха","Николай Годовиков"}
            }
            }
    };

    file << dict[0] << dict[1];

    return 0;
}