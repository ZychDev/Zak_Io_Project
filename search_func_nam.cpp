#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <regex>

//CEL
//Funkcja ma na celu wyszukanie funkcji w danym pliku poprzez regexa

std::map<std::string, std::vector<std::string>> wyszukiwanie2(std::map<std::string, double> pliki)
{

    std::map<std::string, std::vector<std::string>> function_map;
    std::regex rgx("\\b\\w+[A-Za-z0-9_]+(?=\\()");
    std::regex rgx2("(\\.|\\:)\\b\\w+[A-Za-z0-9_]+(?=\\()");
    std::smatch match;
    std::smatch match2;
    std::string key;
    std::string found;

    for (auto it = pliki.begin(); it != pliki.end(); ++it)
    {
        if (it->first == "a.out")
        {
        }
        else
        {

            int counter2 = 0;
            int counter = 0;
            std::ifstream plik(it->first);
            while (!plik.eof())
            {
                std::string linijka;
                getline(plik, linijka);

                if (std::regex_search(linijka, match, rgx) && !(std::regex_search(linijka, match2, rgx2)))
                {

                    if (match[0] != "_popen" && match[0] != "popen" && match[0] != "_pclose" && match[0] != "pclose" && match[0] != "file" && match[0] != "if" && match[0] != "for" && match[0] != "graf_plikow" && match[0] != "graf_funkcji" && match[0] != "graf_namespace" && match[0] != "ifile" && match[0] != "ofile" && match[0] != "cfile" && match[0] != "rgb" && match[0] != "while" && match[0] != "rgx" && match[0] != "rgx2" && match[0] != "plik" && match[0] != "getline" && match[0] != "fgets" && match[0] != "DODAWANIE" && match[0] != "MAPA")
                    {

                        found = match[0];

                        if (counter == 0)
                        {
                            key = found;
                        }

                        if (found != key)
                        {
                            function_map[key].push_back(found);
                        }
                        else if (found == key)
                        {
                            function_map[key].push_back("");
                        }
                    }
                }

                if (linijka.find("{") != std::string::npos && linijka.find("class") == std::string::npos)
                {
                    ++counter;
                    //std::cout << "counter wynosi " << counter << " w " << found << std::endl;
                }

                if (linijka.find("}") != std::string::npos)
                {
                    --counter;
                    //std::cout << "counter wynosi " << counter << " w " << found << std::endl;
                }

                counter2++;
            }
        }
    }

    return function_map;
}
