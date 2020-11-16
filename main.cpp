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

    DODAWANIE();

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

    
    MAPA();

    for(auto it = struktura.begin() ; it != struktura.end() ; ++it ){
        for(auto i = it->second.begin() ; i != it->second.end() ; ++i){
            std::cout<<"Klucz: "<< it->first<<"    Elementy:    "<<*i<<std::endl;
        }
    }

    int x = lista.size()  ;
    for(auto n = lista.begin() ; n != lista.end() ; ++n)
    {
        std::cout<<*n<<std::endl;
    }

    return 0;

}
