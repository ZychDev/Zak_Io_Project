#include <iostream>
#include <list>
#include <string>
//przypiete pliki
#include "graph.cpp"
#include "listing.cpp"
#include "search_func_nam.cpp"
#include "search_namespace.cpp"
#include "s_names_names.cpp"
#include "Mateusz_name_fun.cpp"
#include "convert.cpp"
#include "files_functions_dep.cpp"
//CEL
//Program glowny ktory ma opcje wybory rysowanego grafu
//tutaj sa tworzone klasy graph 
//momentami przed stworzeniem klasy trzeba lekko edytowac niektore struktury dlatego jest pare linijek kodu wiecej typu "czyszczenie struktur"

std::vector<std::string> lista_nam;
std::map<std::string, std::vector<std::string>> lista_namesapce;
namespace jeden
{
    namespace dwa
    {
        void wyswietl2()
        {
            std::cout << "TRUE" << std::endl;
        }
    } // namespace dwa
} // namespace jeden

namespace trzy
{
    void wyswietl()
    {
        std::cout << "FALSE" << std::endl;
    }
} // namespace trzy







int main()
{
    std::cout << "Hello enter path to folder with program " << std::endl;
    std::string path;
    std::cin>>path;
    std::cout << "Choose the graph you are interested in " << std::endl;
    std::cout << "1.Files  \n2.Namespaces  \n3.Functions  \n4.Pliki - Funkcje \n5.Pliki - Namespaces" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::map<std::string, double> x = listing(path);
        Graph graf_plikow(x);
        break;
    }
    case 2:
    {
        std::map<std::string, double> x = listing(path);
        trzy::wyswietl();
        jeden::dwa::wyswietl2();
        std::vector<std::string> z = wyszukiwanie_name_ciag(x);
        Graph graf_namespace_pliki(z);

        break;
    }
    case 3:
    {

        std::map<std::string, double> x = listing(path);
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
        Graph graf_funkcji(z);
        break;
    }
    case 4:
    {
        std::map<std::string, double> x = listing(path);
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
        std::map<std::string, std::vector<std::string>> tmp;

        //oczyszczenie mapy jasia
        for (auto i = z.begin(); i != z.end(); ++i)
        {
            for (auto j = i->second.begin(); j != i->second.end(); ++j)
            {
                if (i->first != " " && *j != " " && *j != "")
                {
                    tmp[i->first].push_back(*j);
                }
            }
        }
        
        std::vector<std::string> files = map_string_double_TO_string(x);
        std::map<std::string, std::list<std::string>> functions = map_second_element_on_list_string(tmp);
        std::map<std::string, std::map<std::string, std::list<std::string>>> combine = pliki_fun(files, functions);
        
        Graph graf_pliki_funkcje(combine);
        break;
    }
    case 5:
    {
        std::map<std::string, double> x = listing(path);
        trzy::wyswietl();
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie_name(x);
        Graph graf_namespace_pliki(z);
        break;
    }
    case 6:
    {
        std::cout<<"Funkcje - Namespace"<<std::endl;
        std::map<std::string, double> y = listing(path);
        std::map<std::string, std::vector<std::string>> c = wyszukiwanie2(y);
        std::map<std::string, std::vector<std::string>> tmp;

        //oczyszczenie mapy jasia
        for (auto i = c.begin(); i != c.end(); ++i)
        {
            for (auto j = i->second.begin(); j != i->second.end(); ++j)
            {
                if (i->first != " " && *j != " " && *j != "")
                {
                    tmp[i->first].push_back(*j);
                }
            }
        }
        
        std::vector<std::string> files = map_string_double_TO_string(y);
        std::map<std::string, std::list<std::string>> functions = map_second_element_on_list_string(tmp);
        std::map<std::string, std::map<std::string, std::list<std::string>>> combine = pliki_fun(files, functions);

        

        function_namespce_functions(combine);
        
        break;
    }
    default:
    {
        std::cout << "End of the program" << std::endl;
        break;
    }
    }

    return 0;
}
