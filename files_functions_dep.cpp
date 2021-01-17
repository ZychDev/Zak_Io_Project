#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <list>

//CEL
//funkcja ma na celu odszukac nazwy uzytych funkcji w danym pliku (przechodzi po nim linijka po linijce szukajac frazy)
//oraz zwrocic strukture polaczen typu plik -> funkcja

std::map<std::string, std::map<std::string, std::list<std::string>>> pliki_fun(std::vector<std::string> pliki, std::map<std::string, std::list<std::string>> mapa_funkcji)
{
    std::map<std::string, std::map<std::string, std::list<std::string>>> mapaa;

    for (auto it = pliki.begin(); it != pliki.end(); ++it)
    {
        std::ifstream plik(*it);

        while (!plik.eof())
        {
            std::string linijka;
            getline(plik, linijka);
            for (auto iter = mapa_funkcji.begin(); iter != mapa_funkcji.end(); iter++)
            {
                std::string szukany = iter->first;
                size_t miejsce = linijka.find(szukany);

                for (auto list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
                {
                    if (miejsce != std::string::npos)
                    {
                        mapaa[*it][iter->first] = iter->second;
                    }
                }
            }
        }
    }

    for (auto it = pliki.begin(); it != pliki.end(); ++it)
    {
        std::ifstream plik(*it);
        while (!plik.eof())
        {
            std::string linijka;
            getline(plik, linijka);
            for (auto iter = mapa_funkcji.begin(); iter != mapa_funkcji.end(); iter++)
            {
                for (auto j = iter->second.begin(); j != iter->second.end(); ++j)
                {
                    std::string szukany = *j;
                    size_t miejsce = linijka.find(szukany);

                    for (auto list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
                    {
                        if (miejsce != std::string::npos)
                        {
                            mapaa[*it][*j];
                        }
                    }
                }
            }
        }
    }

    return mapaa;
}