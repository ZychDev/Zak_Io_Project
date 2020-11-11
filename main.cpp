#include<iostream>
#include"graph.cpp"
#include"listing.cpp"
#include<list>
#include"search2.cpp"
std::vector<std::string> lista;
std::map<std::string, std::list<std::string>> struktura;
int main()
{
    DODAWANIE();
   Graph nowa(listing());
    MAPA();
    Graph nowaa(struktura);
    
    return 0;

}
