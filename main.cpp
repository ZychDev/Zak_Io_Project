#include<iostream>
#include"graph.cpp"
#include"listing.cpp"
#include<list>
#include"search3.cpp"
#include"search_func_nam.cpp"
#include<string>
//struktury przechowujace strukture namespace w projekcie
std::vector<std::string>lista_nam;
std::map<std::string, std::vector<std::string>> lista_namesapce;


int main()
{
    std::cout<<"Hello choose the graph you are interested in "<<std::endl;
    std::cout<<"1.Files  \n2.Namespaces in progress  \n3.Functions  \n4.Pliki - Funkcje"<<std::endl;
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
        //namespace
        break;
    }
    case 3:
    {
        std::map<std::string, double> x = listing();
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
        Graph graf_funkcji(z);
    }
    case 4:
    {
        std::map<std::string, double> x = listing();
        std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
        std::map<std::string, std::vector<std::string>> tmp;
        
        //oczyszczenie mapy jasia
        for(auto i = z.begin() ; i != z.end() ; ++i)
            {
                for(auto j = i->second.begin() ; j != i->second.end() ; ++j)
                {
                    if(i->first !="" && *j != "")
                    {
                        tmp[i->first].push_back(*j);
                    }
                }

            }

        Graph graf_pliki_funkcje(x , tmp);
    }
    default:
    {
        std::cout<<"End of the program"<<std::endl;
        break;
    }
    }

    return 0;
}
