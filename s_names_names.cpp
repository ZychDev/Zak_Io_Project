#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<fstream>
#include<string>
#include <sstream>
#include <stdio.h>

#include<stdlib.h>
#include<stdexcept>
#include<algorithm>
#include<cstring>
#include <sys/stat.h>

//funkcja wyszukujaca miejsca w plikach z #include oraz 
//wyłuskująca nazwy zaincludowanych plikow
std::vector<std::string> wyszukiwanie_name_ciag(std::map<std::string, double> pliki) {

    std::map<std::string, std::vector<std::string>>  mapa;
    std::vector<std::string> test;
    //iteracja po liscie plikow
    for (auto it = pliki.begin(); it != pliki.end(); ++it)
    {

        int counter = 0;
        std::ifstream plik(it->first);

        //przeszukiwanie linijka po linijce
        while (!plik.eof())
        {
            std::string linijka;
            getline(plik, linijka);
            std::string szukany = "::"; // ::
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
                    std::string delimiter = "::";

                    size_t pos = 0;
                    std::string token;
                    while ((pos = s.find(delimiter)) != std::string::npos)
                    {
                        token = s.substr(0, pos);
                        s.erase(0, pos + delimiter.length());
                        std::string x = token;

                 
                        test.push_back(x);
                    }
                    test.push_back(s);
                    test.push_back(".");
                }
            }
        }
    }


//show vector
   

    //split vector 
       
    
for(auto i = test.begin() ; i != test.end() ; ++i)
{
    std::cout<<*i<<std::endl;
}

    return test;
}
