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

std::map<std::string, std::vector<std::string>> test(std::map<std::string, double> pliki)
{

    std::map<std::string, std::vector<std::string>> function_map;
    std::vector<std::string> test;


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
                        //std::cout<<"found: "<< found<<std::endl;

                        if (counter == 0)
                        {
                            key = found;
                            //std::cout<<"Tutaj chyba jak juz sie zamyka: "<<key<<std::endl;
                        }

                        if (found != key)
                        {
                            function_map[key].push_back(found);

                        }
                        else if (found == key)
                        {
                            function_map[key].push_back("");


                            

                                int counter = 0;
                                std::ifstream plik(it->first);

                                //przeszukiwanie linijka po linijce
                                while (!plik.eof())
                                {
                                    std::string linijeczka;
                                    getline(plik, linijeczka);
                                    std::string szukany =key; 
                                    // to ta funkcja ktora jest ok jezlei ja znajdzie odpal szukanie od tego momentu namespace
                                    //tylko trzeba jakos zamknac szykanie jezeli odnajdzie nawias wasaty



                                    std::string linijka;
                                    getline(plik, linijka);
                                    std::string szukany = "::"; // ::
                                    size_t miejsce = linijka.find(szukany);

                                    if (miejsce != std::string::npos)
                                    {
                                        std::string szukany2 = "std";
                                        size_t miejsce2 = linijka.find(szukany2);
                                        if (miejsce2 != std::string::npos)
                                        {
                                        }
                                        else
                                        {

                                            std::string s = linijka;
                                            std::string delimiter = "::";

                                            size_t pos = 0;
                                            std::string token;
                                            while ((pos = s.find(delimiter)) != std::string::npos)
                                            {
                                                token = s.substr(0, pos);
                                                s.erase(0, pos + delimiter.length());
                                                std::string x = token;
                                                //remove blank space 
                                                x.erase(remove(x.begin(), x.end(), ' '), x.end());

                                                test.push_back(x);
                                                std::cout<<"To jest x:     "<<x<<"     Dla pliku: "<<it->first<< "     Oraz funkcji: "<<key<<std::endl;
                                            }
                                            test.push_back(s);
                                            test.push_back(".");
                                            }
                                        }
                                    }
                                
















                        }
                    }
                }








                if (linijka.find("{") != std::string::npos && linijka.find("class") == std::string::npos)
                {
                    ++counter;
                }

                if (linijka.find("}") != std::string::npos)
                {
                    --counter;
                }

                counter2++;
            }
        }
    }

    return function_map;
}
