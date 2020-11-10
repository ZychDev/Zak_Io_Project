#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>
#include <iostream>
extern std::list<std::string>lista;

    std::map<std::string, double> listing()
    {
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
        lista.push_back(__func__);


        return map_name_size;

    }