#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
std::string git_version()
{
    std::string wersja;
    std::system("git log --pretty=%H -1 >test.txt");
    //std::cout << std::ifstream("test.txt").rdbuf();

    std::fstream uchwyt; //obiekt typu fstream (uchwyt do pliku)
 
    uchwyt.open("test.txt"); //otwieramy plik: plik.txt (plik - nazwa pliku, txt - rozszerzenie)
    std::string linia;
    do
    {
        getline(uchwyt, linia); //pobierz linijkę
        if(linia != " ")
        {
            wersja = linia;
            return wersja;
        }
    }
    while(linia != ""); //przerwij jeżeli linia będzie pusta (dane w pliku się skończą) UWAGA: Pamiętaj, żeby w pliku zostawić ostatnią linijkę pustą
 
    uchwyt.close(); //zamykamy plik
    
    return wersja;
}