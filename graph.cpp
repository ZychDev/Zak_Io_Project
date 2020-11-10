#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"search_include.cpp"
#include<stdexcept>
#include<string>
#include<sstream>
#include<list>
extern std::list<std::string>lista;

class Graph
{

    public:

        Graph(std::map<std::string, double> Files)
        {
             lista.push_back(__func__);

            //selekcja plikow #include
            std::map<std::string, std::vector<std::pair<std::string,double>>>  l;
            l= wyszukiwanie(Files);  
            std::map<std::string, double> x = Files;
            





            Save_In_File(l,x);


        };

        void Save_In_File(std::map<std::string, std::vector<std::pair<std::string,double>>> l,std::map<std::string, double> x)
        {
            lista.push_back(__func__);
            std::string name = "graf.dot";
            std::ofstream file(name);
            file << "digraph files_graph\n{\n";
            for (auto i = l.begin(); i != l.end(); ++i) 
            {
                if(i->first != "a.out")
                {
                    for(auto j=i->second.begin(); j!=i->second.end() ; ++j)
                    {



                        for(auto n = x.begin() ; n != x.end() ; ++n)
                        {
                            std::cout<<"Nazwa pliku: "<< n->first<<" Value: "<<n->second<<std::endl;


                            if(n->first == i->first)
                            {
                                int value = n->second;
                                std::string f_str = std::to_string (value);
                                file << '"' << j->first<< "->" << '"'<<i->first   << '"' << "[taillabel = "+std::to_string (value)+"]"<< "[label = 1]"<< "\n";
                            }

                        }


                        


                    }
                 }
            }

                file << "}";
                file.close();




                std::string word = "dot -Tpng -O graf.dot";
                int n = word.length();
                char array[n+1];
                strcpy(array , word.c_str());

            exec(array);
        }

        std::string exec(const char* cmd) 
        {
            lista.push_back(__func__);

            char buffer[128];
            std::string result = "";
            FILE* pipe = popen(cmd, "r");
            if (!pipe) throw std::runtime_error("popen() failed!");
            try {
                while (fgets(buffer, sizeof buffer, pipe) != NULL) 
                {
                    result += buffer;
                }
                } catch (...) {
                    pclose(pipe);
                    throw;
                }
            pclose(pipe);

            return result;
        }


};


