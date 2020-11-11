#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>
#include <iostream>
#include"search2.cpp"
extern std::vector<std::string> lista;
extern std::map<std::string, std::list<std::string>> struktura;
    std::map<std::string, double> listing()
    {
        DODAWANIE();

        std::map<std::string, double> map_name_size;
        std::string sciezka;
        std::cout << "Podaj sciezke do folderu " << std::endl;
        std::cin >> sciezka;
        for (auto& entry : std::filesystem::directory_iterator(sciezka))
        {
            if (std::filesystem::is_directory(std::filesystem::path(entry)) != 1)
            {
                
                map_name_size[std::filesystem::path(entry).filename().string()] = std::filesystem::file_size(entry);
                
            }
        }

        MAPA();

        return map_name_size;

    }