#include <string>
#include <iostream>
#include <vector>
#include <map>
#include<list>

std::map< std::string, std::map<std::string, std::list<std::string>>> pliki_fun(std::vector<std::string> pliki, std::map< std::string, std::list<std::string >> mapa_fun) 
{
    std::map< std::string, std::map<std::string, std::list<std::string>>> mapa;

    for (auto it = pliki.begin(); it != pliki.end(); ++it) 
    {
        std::ifstream plik(*it);

        while (!plik.eof()) {
            std::string linijka;
            getline(plik, linijka);
            for (auto iter = mapa_fun.begin(); iter != mapa_fun.end(); iter++)
            {
                std::string szukany = iter->first;
                size_t miejsce = linijka.find(szukany);

                for (auto list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
                {
                    if (miejsce != std::string::npos)
                    {
                        mapa[*it][iter->first] = iter->second;
                    }
                }
            }
        }
    }
    return mapa;
}