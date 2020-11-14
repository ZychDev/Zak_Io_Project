#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>
#include"search2.cpp"

//globalne struktory do przechowywania plikow i ich wag
extern std::vector<std::string> lista;
extern std::map<std::string, std::list<std::string>> struktura;

//funkcja listujaca wszystkie pliki w wybranym przez uzytkownika folderze 
    std::map<std::string, double> listing()
    {
        dodawanie();    //makro do listowania funkcji

        //deklaracja zmiennych i przyjecie sciezki od uzytkownika
        std::map<std::string, double> map_name_size;
        std::string sciezka;
        std::cout << "Podaj sciezke do folderu " << std::endl;
        std::cin >> sciezka;

        //iteracja po folderze oraz wyłuskanie nazw plikow
        for (auto& entry : std::filesystem::directory_iterator(sciezka))
        {
            if (std::filesystem::is_directory(std::filesystem::path(entry)) != 1)
            {
                
                map_name_size[std::filesystem::path(entry).filename().string()] = std::filesystem::file_size(entry);
                
            }
        }

        //makro do listowania funkcji
        //MAPA();
        mapa();
        return map_name_size;

    }