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
}movie,movie1,movie2;//,movie3,movie4;

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
                      {"Director",movie.director = "Some Name"},
                  {"Actors:", movie.actors = {{"Gleb Zheglov",    "Vysotskiy"},
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
                      }},
              {"Movie title",movie1.movieTitle = "The Matrix"},{
               {"Country",movie1.country = "USA"},
                      {"Production date",movie1.productionDate = 1999},
                      {"Company",movie1.company = "Warner Brothers"},
                      {"Script author",movie1.scriptAuthor = "Wachowski Lilly\n"
                                                             "Wachowski Lana\n"
                                                             ""},
                      {"Director",movie1.director = "Wachowski"},
                      {"Actors:",movie1.actors = {{"Neo",    "Keanu Reeves"},
                                                  {"Morpheus", "Laurence Fishbourne"},
                                                  {"Trinity",        "Carrie-Anne Moss"},
                                                  {"Cypher",  "Joe Pantoliano"},
                                                  {"Agent Smith","Hugo Weaving"},
                                                  {"The Oracle","Glogia Foster"}
                      }
                      }}

      };

      file << dict;
      file.close();

    std::ifstream i("movie.json");
    nlohmann::json j;
    i >> j;

   for(const auto& item : j.items())
    {
        std::cout << item.key() << std::endl;
        for(const auto& val :item.value().items())
        {
            std::cout << " " << val.key() << ":" << val.value() << std::endl;
        }
    }
    /*for (auto& [key, val] : j.items())
    {

        if(val.contains("Keanu Reeves"))
        {
            std::cout << "found" << std::endl;
        }else{std::cout <<"not found" << std::endl;}
       // std::cout << "key: " << key << ", value:" << val << '\n';
    }*/
   /* for(const auto& item : j.items())
    {
        std::cout << item.key() << std::endl;
        std::cout << item.value().get<std::string>() << std::endl;
    }*/

    i.close();
}