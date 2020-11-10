#include <iostream>
#include <string_view>
#include <list>
#include <map>
#include <string>
#include <fstream>
using namespace std;

//deklaracja potrzebnych struktur
list<string> lista;
map<string, list<string>> struktura;
ofstream MyFile("funkcje.txt");

//makro dodajace nazwe funkcji di listy
#define DODAWANIE() do{ \
    MyFile << __func__ << endl; \
} while(0);

/*
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
*/

//funkcje do testowania
void funkcja3(){
    DODAWANIE();
    cout << "Jestem funkcją 3" << endl;
   // MAPA();
}
void funkcja2(){
    DODAWANIE();
    cout << "Jestem funkcją 2" << endl;
    funkcja3();
   // MAPA();
}
void funkcja1(){
    DODAWANIE();
    cout << "Jestem funkcją 1" << endl;
    funkcja2();
    funkcja3();
    //MAPA();
}



int main(){

    funkcja1();
    ofstream MyFile("funkcje.txt");    

    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << (*it) << endl;
        MyFile << (*it) << endl;
    }  
    
    MyFile.close(); 
}