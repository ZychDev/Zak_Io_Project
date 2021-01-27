#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
std::string git_version()
{
    std::string wersja;
    std::system("git log --pretty=%H -1 >test.txt");
    

    std::fstream uchwyt; 
 
    uchwyt.open("test.txt"); 
    std::string linia;
    do
    {
        getline(uchwyt, linia); 
        if(linia != " ")
        {
            wersja = linia;
            return wersja;
        }
    }
    while(linia != ""); 
 
    uchwyt.close(); 
    
    return wersja;
}