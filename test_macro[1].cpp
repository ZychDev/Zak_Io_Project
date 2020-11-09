#include <iostream>
#include <string_view>
#include <list>
#include <map>
using namespace std;

//deklaracja potrzebnych struktur
list<string> lista;
map<string, list<string>> mapa;

//makro dodajace nazwe funkcji di listy
#define DODAWANIE() do{ \
    lista.push_back(__func__); \
} while(0);

//makro sprawdzajace na koncu funkcji, jakie funkcje są w niej zawarte (in progress)
#define MAPA() do{\
    for(auto it = lista.begin(); it != lista.end(); ++it) { \
        if(it != _func_){ \
            mapa[__func__].push_back(it); \
        }\
    }\
    }while(0); \

//funkcje do testowania
void funkcja3(){
    DODAWANIE();
    cout << "Jestem funkcją 3" << endl;
}
void funkcja2(){
    DODAWANIE();
    cout << "Jestem funkcją 2" << endl;
    funkcja3();
}
void funkcja1(){
    DODAWANIE();
    cout << "Jestem funkcją 1" << endl;
    funkcja2();
    funkcja3();
}



int main(){

    funkcja1();    
    //wypisywanie listy
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << (*it) << endl;
    }  
    //wypisywanie mapy (nie wypisuje wiec cos jest nie tak)
    for (auto it = mapa["funkcja1"].begin(); it != mapa["funkcja1"].end(); ++it) {
        cout << (*it) << endl;
    }  
     
}