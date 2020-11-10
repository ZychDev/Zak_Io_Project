#include<iostream>
#include"graph.cpp"
#include"listing.cpp"
#include<list>

std::list<std::string>lista;

int main()
{
    lista.push_back(__func__);
   Graph nowa(listing());

   for(std::list<std::string>::iterator it = lista.begin() ; it != lista.end() ; ++it)
    {
        std::cout<<*it<<std::endl;
    }

    
    return 0;

}
