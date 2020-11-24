#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<fstream>
#include<string>
#include<list>
#include <regex>


std::map<std::string, std::vector<std::pair<std::string,double>>> wyszukiwanie2(std::map<std::string, double> pliki) {

    int counter = 0;
    std::map<std::string, std::vector<std::pair<std::string,double>>>  mapaa;
    std::regex rgx("\\b\\w+[A-Za-z0-9_]+(?=\\()");
    std::regex rgx2("(\\.|\\:)\\b\\w+[A-Za-z0-9_]+(?=\\()");
    std::smatch match;
    std::smatch match2;

    for (auto it = pliki.begin(); it != pliki.end(); ++it) {
    std::ifstream plik(it->first);

    while(!plik.eof()){
        
        std::string linijka;
        getline(plik, linijka);

        if (std::regex_search(linijka, match, rgx) && !(std::regex_search(linijka, match2, rgx2))){
            counter++;
            std::cout << "funkcja " << counter << " " << match[0] << '\n';

        }
    }

        // mapaa[it->first].push_back(std::make_pair(nazwa_pliku,it->second));         
    }
     
    return mapaa;
    
}

