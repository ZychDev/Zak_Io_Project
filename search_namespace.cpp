#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <list>

//CEL
//funkcja wyszukujaca miejsca w plikach z "namespace" oraz
//wyłuskująca nazwy zaincludowanych plikow

std::map<std::string, std::vector<std::string>> wyszukiwanie_name(std::map<std::string, double> pliki)
{

  std::map<std::string, std::vector<std::string>> mapa;

  //iteracja po liscie plikow
  for (auto it = pliki.begin(); it != pliki.end(); ++it)
  {
    std::ifstream plik(it->first);

    //przeszukiwanie linijka po linijce
    while (!plik.eof())
    {
      std::string linijka;
      getline(plik, linijka);
      std::string szukany = "namespace "; // ::
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
          std::string delimiter = " ";

          size_t pos = 0;
          std::string token;
          while ((pos = s.find(delimiter)) != std::string::npos)
          {
            token = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
          }
          if (s != "namespace")
          {
            if (it->first == "a.out")
            {
              break;
            }
            mapa[it->first].push_back(s);
          }
        }
      }
    }
  }

  return mapa;
}
