#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "nlohmann_json/include/nlohmann/json.hpp"

struct Movie
{
    std::string movieTitle;
    std::string country;
    int productionDate = 0;
    std::string company;
    std::string scriptAuthor;
    std::string director;
    //std::string producer;
    std::unordered_map<std::string,std::string>actors;
}movie,movie2;//,movie3,movie4,movie5;

int main()
{
    std::string findName;
     std::ofstream file("movie.json");
      nlohmann::json dict = {
              {"Movie title",movie.movieTitle = "Mesto vstrechi izmenit nelzya"},{
                  {"Country",movie.country = "USSR"},
                  {"Production date",movie.productionDate = 1979},
                  {"Company",movie.company = "Odessa kinokompany"},
                  {"Script author",movie.scriptAuthor = "Stanislav Govorukhin"},
                      {"Director",movie2.director = "Some Name"},
                  {"Actors:", movie.actors = {{"Gleb Zheglov",    "Vladimir Vysotskiy"},
                                              {"Volodya Sharapov", "Vladimir Konkin"},
                                              {"Grudsev",        "Sergey Yurskiy"},
                                              {"Petr Ruchnikov ",  "Evgeniy Evstigneev"},
                                              {"Man'ka Obligatsiya","Larisa Udovichenko"}
                      }
                  }},
              {"Movie title",movie2.movieTitle = "Beloye Solnze pustyni"},{
               {"Country",movie2.country = "USSR"},
               {"Production date",movie2.productionDate = 1969},
                      {"Company",movie2.company = "Mosfolm, Lenfilm"},
                      {"Script author",movie2.scriptAuthor = "Valentin Ezhov\n"
                                             "Rustam Ibragimbekov\n"
                                             "Mark Zakharov"},
                      {"Director",movie2.director = "Vladimir Motyl"},
                      {"Actors:",movie2.actors = {{"Fyodor Sukhov",    "Anatoliy Kuznetzov"},
                                        {"Said", "Spartak Mishulin"},
                                        {"Abdulla",        "Kakhi Kavasadze"},
                                        {"Vereschagin",  "Pavel Luspekaev"},
                                        {"Gyul'chatay","Tatyana Fedotova"},
                                        {"Petrukha","Nikolay Godovikov"}
                      }
                      }}

      };

      file << dict;
     file.close();

    std::ifstream i("movie.json");
    nlohmann::json j;
    i >> j;
    std::cout << "Enter name of actor you want to know about:";
    std::cin >> findName;
    for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
       /* if(it.value()["Actors"] == findName)
        {
            std::cout << it.value()["movieTitle"];
        }*/
        std::cout << *it << '\n';
    }
    i.close();
}