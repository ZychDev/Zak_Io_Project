#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<fstream>
#include<string>
#include<list>


//funkcja wyszukujaca miejsca w plikach z #include oraz 
//wyłuskująca nazwy zaincludowanych plikow
std::map<std::string, std::vector<std::string>> wyszukiwanie_name(std::map<std::string, double> pliki) {

    std::map<std::string, std::vector<std::string>>  mapa;

    //iteracja po liscie plikow
    for (auto it = pliki.begin(); it != pliki.end(); ++it) 
  {
    std::ifstream plik(it->first);

    //przeszukiwanie linijka po linijce 
    while(!plik.eof())
    {
        std::string linijka;
        getline(plik, linijka);
        std::string szukany = "::";
        size_t miejsce = linijka.find(szukany);

        if (miejsce != std::string::npos)
            {

              //pominiecie pliku wykonywalnego
              if(it->first == "a.out")
              {break;}

              //push'owanie nazwy pliku do mapy pod kluczem 
              //nazwy pliku, w ktorym zanjduje sie petla
              mapa[it->first].push_back(linijka);         
            }

    }
     
  }
            //macro do listowania funkcji


    return mapa;
    
    }
