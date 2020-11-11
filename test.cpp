#include<iostream>
#include<list>
#include"search2.cpp"

//plik testujacy dzialanie macro

std::vector<std::string> lista;
std::map<std::string, std::list<std::string>> struktura;
void fun1();
void fun2();
void fun3();

void fun1()
{
    DODAWANIE();

    fun2();
    MAPA();

}

void fun2()
{
    DODAWANIE();
    MAPA();

}

void fun3()
{
    DODAWANIE();
    MAPA();
}

int main()
{
    fun1();
    fun3();

    for(auto it = struktura.begin() ; it != struktura.end() ; ++it )
    {
        for(auto i = it->second.begin() ; i != it->second.end() ; ++i)
        {
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