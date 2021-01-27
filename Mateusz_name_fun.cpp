#include <iostream>
#include <fstream>
#include <vector>

void function_namespce_functions(std::map<std::string, std::map<std::string, std::list<std::string>>> combine)
{
    std::vector<std::pair<std::string, std::string>> test;
    std::map<std::string  , std::string> plik_funkcja;

    int counter_open = 0;
    int counter_close = 0;

   
    //przechodzenie po funkcjach
    
    for (auto i = combine.begin(); i != combine.end(); ++i)
    {
        
        std::cout<<"NAZWA PLIKU: "<<i->first<<std::endl;
        std::string name = i->first;

        std::ifstream file(name);
        if (file.is_open())
        {
            std::string line;
            std::string search = "main()"; // najpierw szukam nazwy funkcji
            while (std::getline(file, line))
            {
                size_t miejsce = line.find(search);
                if (miejsce != std::string::npos)
                {
                    std::cout << "Znalazlem Funckje: " << line << std::endl;

                    std::string search2 = "{";
                    while (std::getline(file, line))
                    {
                        size_t miejsce2 = line.find(search2);
                        if (miejsce2 != std::string::npos)
                        {

                            //znalazlem otwarcie wiec przeszukam je w poszukiwaniu names
                            std::string search3 = "wyswietl2";

                            if (line.find("{") != std::string::npos)
                            {
                                ++counter_open;

                                while (std::getline(file, line))
                                {
                                    if (line.find("{") != std::string::npos)
                                    {
                                        ++counter_open;
                                    }
                                    if (line.find("}") != std::string::npos)
                                    {
                                        --counter_open;
                                        if (counter_open == 0)
                                        {
                                            break;
                                        }
                                        std::cout << line << std::endl;
                                    }

                                    size_t miejsce3 = line.find(search3);
                                    if (miejsce3 != std::string::npos)
                                    {
                                        std::cout << "Znalazłem Namespace: " << line << std::endl;
                                        test.push_back(std::make_pair(search, line));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            std::cout << "Counter Open: " << counter_open << std::endl;

            for (auto i = test.begin(); i != test.end(); ++i)
            {
                std::cout << i->first << " And " << i->second << std::endl;
            }

            file.close();
        }
    }
}

