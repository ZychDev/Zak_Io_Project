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


//makro dodajace nazwe funkcji di listy
#define DODAWANIE() do{ \
    lista.push_back(__func__); \
} while(0); \


//makro sprawdzajace na koncu funkcji, jakie funkcje są w niej zawarte (in progress)
#define MAPA() do{\
std::string a;\
    int i = lista.size() - 1 ; \
    for(i; i >= 0; --i){ \
        if(lista[i] == __func__){ \
            for (int j =i+1; j <= lista.size(); ++j){ \
                if(lista[j] != "")\
                {\
                struktura[__func__].push_back(lista[j]); \
                }\
            } \
            break; \
        } \
        else{\
            struktura[__func__].push_back("");\
        }\
    }\
    }while(0); \



