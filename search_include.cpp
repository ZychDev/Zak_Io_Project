#include<iostream>
#include<list>
#include<algorithm>
#include<map>
#include<vector>
#include<fstream>
#include<string>
#include<list>
#include"search2.cpp"
extern std::vector<std::string> lista;
extern std::map<std::string, std::list<std::string>> struktura;
std::map<std::string, std::vector<std::pair<std::string,double>>> wyszukiwanie(std::map<std::string, double> pliki) {
                    DODAWANIE();

    std::map<std::string, std::vector<std::pair<std::string,double>>>  mapa;
    for (auto it = pliki.begin(); it != pliki.end(); ++it) 
  {
    std::ifstream plik(it->first);
    while(!plik.eof())
    {
        std::string linijka;
        getline(plik, linijka);
        std::string szukany = "#include\"";
        size_t miejsce = linijka.find(szukany );

        if (miejsce != std::string::npos)
            {
              miejsce += szukany.size();
              std::string nazwa_pliku = linijka.substr(miejsce);


              if(it->first == "a.out")
              {break;}
              mapa[it->first].push_back(std::make_pair(nazwa_pliku,it->second));         
            }

    }
     
  }
            MAPA();

    return mapa;
    
    }
