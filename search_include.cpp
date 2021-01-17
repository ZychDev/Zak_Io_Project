#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <list>

//CEL
//funkcja wyszukujaca miejsca w plikach z "#include" oraz
//wyłuskująca nazwy zaincludowanych plikow

std::map<std::string, std::vector<std::pair<std::string, double>>> wyszukiwanie(std::map<std::string, double> pliki)
{

  std::map<std::string, std::vector<std::pair<std::string, double>>> mapaa;

  //iteracja po liscie plikow
  for (auto it = pliki.begin(); it != pliki.end(); ++it)
  {
    std::ifstream plik(it->first);

    //przeszukiwanie linijka po linijce
    while (!plik.eof())
    {
      std::string linijka;
      getline(plik, linijka);
      std::string szukany = "#include \"";
      size_t miejsce = linijka.find(szukany);

      if (miejsce != std::string::npos)
      {
        miejsce += szukany.size();
        std::string nazwa_pliku = linijka.substr(miejsce);

        //pominiecie pliku wykonywalnego
        if (it->first == "a.out")
        {
          break;
        }

        //push'owanie nazwy pliku do mapy pod kluczem
        //nazwy pliku, w ktorym zanjduje sie petla
        mapaa[it->first].push_back(std::make_pair(nazwa_pliku, it->second));
        std::cout << "Funkcja search: " << nazwa_pliku << std::endl;
      }
    }
  }

  return mapaa;
}
