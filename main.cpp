#include<iostream>
#include"graph.cpp"
#include"listing.cpp"
#include<list>
#include"search2.cpp"
#include"search3.cpp"

//struktury przechowujace strukture funkcji w projekcie
std::vector<std::string> lista;
std::map<std::string, std::list<std::string>> struktura;
//struktury przechowujace strukture namespace w projekcie
std::vector<std::string>lista_nam;
std::map<std::string, std::vector<std::string>> lista_namesapce;

//namespace do grafu
namespace jeden
{
    namespace dwa
    {
        void pretty()
        {
            lista_nam.push_back(__PRETTY_FUNCTION__);
        }
    }
}

namespace trzy
{
    namespace jeden
    {
        namespace dwa
        {
            void pretty()
            {
                lista_nam.push_back(__PRETTY_FUNCTION__);
            }
        }
    }
    
}

int main()
{
    //makro do listowania funkcji

    //DODAWANIE();
    dodawanie();

    //wywolanie tworzenia grafu z plikami
    Graph graf_plikow(listing());

    //makro do listowwania funkcji

   
    
    //wywolanie tworzenia grafu z funkcjami 
    Graph graf_funkcji(struktura);

    //wywolanie tworzenia grafu z namesapcem 
    jeden::dwa::pretty();
    trzy::jeden::dwa::pretty();
    segreg_nam();
    Graph graf_namespace(lista_namesapce);

    
    //MAPA();
    mapa();
    return 0;

}
