#include <iostream>
#include <string_view>
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//deklaracja potrzebnych struktur
std::vector<std::string> lista;
std::map<std::string, std::list<std::string>> struktura;

//makro dodajace nazwe funkcji di listy
#define DODAWANIE() do{ \
    lista.push_back(__func__); \
} while(0); \


//makro sprawdzajace na koncu funkcji, jakie funkcje są w niej zawarte (in progress)
#define MAPA() do{\
    int i = lista.size(); \
    for(i; i >= 0; --i){ \
        if(lista[i] == __func__){ \
            for (int j =i+1; j <= lista.size(); ++j){ \
                struktura[__func__].push_back(lista[j]); \
            } \
            break; \
        } \
    }\
    }while(0); \

