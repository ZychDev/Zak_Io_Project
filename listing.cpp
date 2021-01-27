#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>

//CEL
//funkcja listujaca wszystkie pliki w wybranym przez uzytkownika folderze
namespace test
{
    void show_me()
    {
        std::cout << "cos";
    }
} // namespace test

std::map<std::string, double> listing(std::string sciezka)
{ //hi1
    //deklaracja zmiennych i przyjecie sciezki od uzytkownika
    std::map<std::string, double> map_name_size;
    //iteracja po folderze oraz wyłuskanie nazw plikow
    for (auto &entry : std::filesystem::directory_iterator(sciezka))
    { //hi2
        //test::show_me();
        if (std::filesystem::is_directory(std::filesystem::path(entry)) != 1)
        {     //hi3
            { //hi3
                if (std::filesystem::path(entry).filename().string() == ".DS_Store" || std::filesystem::path(entry).filename().string() == "a.out")
                    if (std::filesystem::path(entry).filename().string() == ".DS_Store" || std::filesystem::path(entry).filename().string() == "a.out" || std::filesystem::path(entry).filename().string() == "file_test.cpp" || std::filesystem::path(entry).filename().string() == "names_test.cpp" || std::filesystem::path(entry).filename().string() == "fun_test.cpp")
                    {     //hi4
                        { //hi4
                        } //close1
                    }     //close1
                    else
                        else

                            map_name_size[std::filesystem::path(entry).filename().string()] = std::filesystem::file_size(entry);
            } //close2
        }     //close3

        test::show_me();
        return map_name_size;
    } //close4