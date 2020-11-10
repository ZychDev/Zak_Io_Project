#include <iostream>
#include <string_view>
#include <list>
#include <map>
#include <string>
using namespace std;

//deklaracja potrzebnych struktur
list<string> lista;
map<string, list<string>> struktura;

//makro dodajace nazwe funkcji di listy
#define DODAWANIE() do{ \
    lista.push_back(__func__); \
} while(0);


//makro sprawdzajace na koncu funkcji, jakie funkcje są w niej zawarte (in progress)
#define MAPA() do{\
    int i = lista.size(); \
    for(i; i >= 0; --i){ \
        if(lista[i] == __func__){ \
            for (i; i <= lista.size(); ++i){ \
                struktura[__func__].push_back(lista[i]); \
            } \
            break; \
        } \   
    }\
    }while(0); \


//funkcje do testowania
void funkcja3(){
    DODAWANIE();
    cout << "Jestem funkcją 3" << endl;
    MAPA();
}
void funkcja2(){
    DODAWANIE();
    cout << "Jestem funkcją 2" << endl;
    funkcja3();
    MAPA();
}
void funkcja1(){
    DODAWANIE();
    cout << "Jestem funkcją 1" << endl;
    funkcja2();
    funkcja3();
   MAPA();
}



int main(){

    funkcja1();    
    //wypisywanie listy
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << (*it) << endl;
    }   
     
}