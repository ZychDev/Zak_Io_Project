#include<iostream>
#include"graph.cpp"
#include"listing.cpp"
#include<list>
#include"search2.cpp"

//struktury przechowujace strukture funkcji w projekcie
std::vector<std::string> lista;
std::map<std::string, std::list<std::string>> struktura;

int main()
{
    //makro do listowania funkcji
    DODAWANIE();

    //wywolanie tworzenia grafu z plikami
    Graph nowa(listing());

    //makro do listowwania funkcji
    MAPA();

    //wywolanie tworzenia grafu z ffunkcjami 
    Graph nowaa(struktura);
    
    return 0;

}
