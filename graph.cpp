#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "search_include.cpp"
#include <stdexcept>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
#include <cstring>
#include "files_functions_dep.cpp"
#include <fstream>
#include <sys/stat.h>

namespace cztery
{
    void wyswietl()
    {
        std::cout << "Hi" << std::endl;
    }
} // namespace cztery

class Graph
{

public:
    //1.Pliki
    Graph(std::map<std::string, double> Files)
    {
        std::map<std::string, std::vector<std::pair<std::string, double>>> l;
        l = wyszukiwanie(Files);
        std::map<std::string, double> x = Files;
        std::string name = "pliki.dot";

        for (auto i = l.begin(); i != l.end(); ++i)
        {
        }

        Save_In_File_Files(l, x, name);
    };

    //2.Funkcje
    //tutaj tez jest plilli - name
    Graph(std::map<std::string, std::vector<std::string>> struktura)
    {
        std::string name = "funkcje.dot";
        std::string path = "./folder/" + name;
        std::ifstream fin(path);

        if (fin.is_open())
        {
            std::cout << "Plik juz istnieje" << std::endl;
            name = "pliki_namespace.dot";
            Save_In_File_Func(struktura, name);

        }
        else
        {
            std::cout << "Plik nie istnieje" << std::endl;
            Save_In_File_Func(struktura, name);

        }

    }

    //3.Namespace

    Graph(std::vector<std::string> names)
    {
        std::string name = "names.dot";
        Save_File_n(names, name);
    };

    //4.Pliki - Funckje
    Graph(std::map<std::string, double> pliki, std::map<std::string, std::vector<std::string>> struktura)
    {
        std::vector<std::string> files = map_string_double_TO_string(pliki);
        std::map<std::string, std::list<std::string>> functions = map_second_element_on_list_string(struktura);
        std::map<std::string, std::map<std::string, std::list<std::string>>> combine = pliki_fun(files, functions);//tutaj uzywamy pliki_fun
        std::string name = "pliki_funkcje.dot";
        Save_File_Func(combine, name);
    }
    void Save_File_n(std::vector<std::string> vec, std::string name)
    {
        //std::ofstream file(name);
        std::ofstream file("./folder/" + name);

        file << "digraph files_graph\n{\n";

        for (auto i = vec.begin(); i != vec.end(); ++i)
        {
            if (*i != ".")
            {
                file << '"' << *i << '"' << "->";
            }
            else
            {
                long pos = file.tellp();
                file.seekp(pos - 2);
                file.write("", 2);
                file << std::endl;
            }
        }
        file << "}";
        file.close();
        std::string word = "dot -Tpng -O ./folder/" + name;
        int n = word.length();
        char array[n];
        strcpy(array, word.c_str());

        exec(array);
    }
    std::vector<std::string> map_string_double_TO_string(std::map<std::string, double> pliki)
    {
        std::vector<std::string> tmp;
        for (auto i = pliki.begin(); i != pliki.end(); ++i)
        {
            tmp.push_back(i->first);
        }

        return tmp;
    }

    std::map<std::string, std::list<std::string>> map_second_element_on_list_string(std::map<std::string, std::vector<std::string>> funkcje)
    {

        std::map<std::string, std::list<std::string>> tmp;

        for (auto i = funkcje.begin(); i != funkcje.end(); ++i)
        {
            for (auto j = i->second.begin(); j != i->second.end(); ++j)
            {
                tmp[i->first].push_back(*j);
            }
        }

        return tmp;
    }
    void Save_File_Func(std::map<std::string, std::map<std::string, std::list<std::string>>> combine, std::string name)
    {
        //std::ofstream file(name);
        std::ofstream file("./folder/" + name);

        file << "digraph files_graph\n{\n";

        for (auto i = combine.begin(); i != combine.end(); ++i)
        {
            for (auto j = i->second.begin(); j != i->second.end(); ++j)
            {
                file << '"' << i->first << "\"->" << '"' << j->first << '"' << "\n";
                for (auto z = j->second.begin(); z != j->second.end(); ++z)
                {
                    file << "->\"" << *z << "\"";
                }
            }
        }

        file << "}";
        file.close();
        std::string word = "dot -Tpng -O ./folder/" + name;
        int n = word.length();
        char array[n];
        strcpy(array, word.c_str());

        exec(array);
    }

    void Save_In_File_Namespac(std::string name, std::map<std::string, std::vector<std::string>> names)
    {
        //std::ofstream file(name);
        std::ofstream file("./folder/" + name);

        file << "digraph files_graph\n{\n";
        for (auto it = names.begin(); it != names.end(); ++it)
        {
            for (auto j = it->second.begin(); j != it->second.end(); ++j)
            {
                file << it->first << "->" << *j << std::endl;
            }
        }
        file << "}";
        file.close();
        std::string word = "dot -Tpng -O ./folder/" + name;
        int n = word.length();
        char array[n];
        strcpy(array, word.c_str());
        exec(array);
    }

    int fileExists(const char *fileName)
    {
        FILE *plik;
        plik = fopen(fileName, "r"); /* ważne, by nie tworzyć pliku, jeśli nie istnieje, tryb "r" (tylko odczyt) */
        if (plik)
        {
            fclose(plik);
            return 1;
        }
        fclose(plik);
        return 0;
    }

    bool FileExists(std::string filename)
    {
        struct stat fileInfo;
        return stat(filename.c_str(), &fileInfo) == 0;
    }

    void Save_In_File_Func(std::map<std::string, std::vector<std::string>> l, std::string name)
    {
        //std::ofstream file(name);
        //sprawdzanie czy taki plik istnieje z ta nazwa

        std::ofstream file("./folder/" + name);

        file << "digraph files_graph\n{\n";

        for (auto i = l.begin(); i != l.end(); ++i)
        {
            for (auto j = i->second.begin(); j != i->second.end(); ++j)
            {
                if (*j != "")
                {
                    file << "\"" << i->first << "\""
                         << "->"
                         << "\"" << *j << "\"" << std::endl;
                    std::cout << i->first << "->" << *j << std::endl;
                }
            }
        }
        file << "}";
        file.close();
        std::string word = "dot -Tpng -O ./folder/" + name;
        int n = word.length();
        char array[n];
        strcpy(array, word.c_str());

        exec(array);
    }

    void Save_In_File_Files(std::map<std::string, std::vector<std::pair<std::string, double>>> l, std::map<std::string, double> x, std::string name)
    {
        std::ofstream file("./folder/" + name);
        file << "digraph files_graph\n{\n";
        for (auto i = l.begin(); i != l.end(); ++i)
        {
            if (i->first != "a.out")
            {
                for (auto j = i->second.begin(); j != i->second.end(); ++j)
                {
                    for (auto n = x.begin(); n != x.end(); ++n)
                    {

                        if (n->first == i->first)
                        {
                            int value = n->second;
                            std::string f_str = std::to_string(value);
                            file << '"' << j->first << "->" << '"' << i->first << '"' << "[taillabel = " + std::to_string(value) + "]"
                                 << "[label = 1]"
                                 << "\n";
                        }
                    }
                }
            }
        }

        file << "}";
        file.close();
        std::string word = "dot -Tpng -O ./folder/" + name;
        int n = word.length();
        char array[n];
        strcpy(array, word.c_str());

        exec(array);
    }

    std::string exec(const char *cmd)
    {
#ifdef _WIN32
        _popen(" ", "w");
#else
        popen(" ", "w");
#endif

        char buffer[128];
        std::string result = "";
        FILE *pipe = popen(cmd, "r");
        if (!pipe)
            throw std::runtime_error("fail");
        try
        {
            while (fgets(buffer, sizeof buffer, pipe) != NULL)
            {
                result += buffer;
            }
        }
        catch (...)
        {
            pclose(pipe);
            throw;
        }
        pclose(pipe);
        return result;
    }
};
