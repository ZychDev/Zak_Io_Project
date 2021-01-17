#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>

//CEL
//funkcja listujaca wszystkie pliki w wybranym przez uzytkownika folderze

std::map<std::string, double> listing(std::string sciezka)
{
    //deklaracja zmiennych i przyjecie sciezki od uzytkownika
    std::map<std::string, double> map_name_size;
    
    //iteracja po folderze oraz wyłuskanie nazw plikow
    for (auto &entry : std::filesystem::directory_iterator(sciezka))
    {
        if (std::filesystem::is_directory(std::filesystem::path(entry)) != 1)
        {
            if (std::filesystem::path(entry).filename().string() == ".DS_Store" || std::filesystem::path(entry).filename().string() == "a.out")
            {
            }
            else

                map_name_size[std::filesystem::path(entry).filename().string()] = std::filesystem::file_size(entry);
        }
    }
    return map_name_size;
}