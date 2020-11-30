#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>

extern std::vector<std::string>lista_nam;
extern std::map<std::string, std::vector<std::string>> lista_namesapce;
std::vector<std::string>lista_nam_final;
void segreg_nam()
{

    for(int i = 0; i<lista_nam.size() ; ++i)
    {
        std::string sentence=lista_nam[i];
        sentence=sentence.substr(sentence.find_first_of(" \t")+1);
        lista_nam[i] = sentence;
         
    }


    for(int i = 0; i<lista_nam.size() ; ++i)
    {
        std::vector<std::string>lista_nam_final;

        std::string s = lista_nam[i];
        std::string delimiter = "::";
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) 
        {
            token = s.substr(0, pos);
            lista_nam_final.push_back(token);
            s.erase(0, pos + delimiter.length());
            
        }
        for(int j = 1 ; j != lista_nam_final.size() ; ++j)
        {
            lista_namesapce[lista_nam_final[0]].push_back(lista_nam_final[j]);
        }
    }

}
