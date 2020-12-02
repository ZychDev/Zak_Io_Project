#include<iostream>
#include"graph.cpp"
#include"listing.cpp"
#include<list>
#include"search3.cpp"
#include"search_func_nam.cpp"
#include<string>
#include"search_namespace.cpp"
#include"s_names_names.cpp"
std::vector<std::string>lista_nam;
std::map<std::string, std::vector<std::string>> lista_namesapce;
namespace jeden
{
    namespace dwa
    {
        void wyswietl2()
        {
            std::cout << "Hi 2 " << std::endl;
        }
    } 
} 

namespace trzy
{
    void wyswietl()
    {
        std::cout<<"Hi"<<std::endl;
    }
}

int main()
{
    std::cout<<"Hello choose the graph you are interested in "<<std::endl;
    std::cout<<"1.Files  \n2.Pliki - Namespaces  \n3.Functions  \n4.Pliki - Funkcje \n5.Namespaces"<<std::endl;
    int choice;
    std::cin>>choice;

    switch (choice)
    {
    case 1:
    {
        std::map<std::string, double> x = listing();
        Graph graf_plikow(x);
        break;
    }
    case 2:
    {   
        std::map<std::string, double> x = listing();
        trzy::wyswietl();
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie_name(x);
        for(auto i = z.begin() ; i != z.end() ; ++i)
        {
            std::cout<<i->first<<":   ";
            for(auto j = i->second.begin() ; j != i->second.end() ; ++j)
            {
                std::cout<<*j<<" , ";
            }
            std::cout<<std::endl;
        }
        


        Graph graf_namespace_pliki(z);

        break;
    }
    case 3:
    {
        
        std::map<std::string, double> x = listing();
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
        Graph graf_funkcji(z);
        break;
    }
    case 4:
    {
        std::map<std::string, double> x = listing();
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
        std::map<std::string, std::vector<std::string>> tmp;
        
        //oczyszczenie mapy jasia
        for(auto i = z.begin() ; i != z.end() ; ++i)
            {
                //std::cout<<"Klucz: "<<i->first<<std::endl;
                for(auto j = i->second.begin() ; j != i->second.end() ; ++j)
                {
                    if(i->first !=" " && *j != " " && *j != "")
                    {
                        tmp[i->first].push_back(*j);
                    }
                }

            }

            for(auto i = tmp.begin() ; i != tmp.end() ; ++i)
            {
                std::cout<<"Klucz: "<<i->first<<std::endl;
                for(auto j = i->second.begin() ; j != i->second.end() ; ++j)
                {
                    std::cout<<*j<<std::endl;
                }

            }

        Graph graf_pliki_funkcje(x , tmp);
    }
    case 5:
    {
        std::map<std::string, double> x = listing();
        trzy::wyswietl();
        jeden::dwa::wyswietl2();
        std::vector<std::string> z = wyszukiwanie_name_ciag(x);
       


        Graph graf_namespace_pliki(z);


        break; 
    }
    default:
    {
        std::cout<<"End of the program"<<std::endl;
        break;
    }
    }

    return 0;
}
