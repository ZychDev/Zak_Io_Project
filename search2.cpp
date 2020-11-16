#include <iostream>
#include <string_view>
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#ifndef search2
#define search2

//deklaracja potrzebnych struktur

extern std::vector<std::string> lista;
extern std::map<std::string, std::list<std::string>> struktura;


//makro dodajace nazwe funkcji di listy


#define DODAWANIE() do{ \
    lista.push_back(__func__); \
} while(0); \

/*
void dodawanie(){
    if(lista.back() == "dodawanie" && lista.end()[-2] == "dodawanie"){}
    else{
        lista.push_back(__func__);
    }
}
*/


//makro sprawdzajace na koncu funkcji, jakie funkcje są w niej zawarte

#define MAPA() do{\
std::string a;\
    int i = lista.size() - 1 ; \
    for(i; i >= 0; --i){ \
        if(lista[i] == __func__){ \
            for (int j =i+1; j < lista.size(); ++j){ \
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

/*
void mapa(){
    //static std::map<std::string, std::list<std::string>> struktura;
    std::string a; 
    int i = lista.size() - 1;
    for(i; i >= 0; --i){ 
        if(lista[i] == __func__){ 
            for (int j =i+1; j <= lista.size(); ++j){ 
                if(lista[j] != ""){
                struktura[__func__].push_back(lista[j]); 
                }
            } 
            break; 
        } 
        else{
            struktura[__func__].push_back("");
        }
    }
}

*/
#endif

