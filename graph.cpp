#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"search_include.cpp"
#include<stdexcept>
#include<string>
#include<sstream>
#include<list>
#include"search2.cpp"
extern std::vector<std::string> lista;
extern std::map<std::string, std::list<std::string>> struktura;
class Graph
{

    public:

        Graph(std::map<std::string, double> Files)
        {

            //selekcja plikow #include
            std::map<std::string, std::vector<std::pair<std::string,double>>>  l;
            l= wyszukiwanie(Files);  
            std::map<std::string, double> x = Files;
            std::string name = "graf.dot";





            Save_In_File(l,x,name);


        };

        Graph(std::map<std::string, std::list<std::string>> struktura)
        {
            
            for(auto it = struktura.begin() ; it != struktura.end() ; ++it)
            {
                    for(auto i = it->second.begin() ; i != it->second.end() ; ++i)
                    {
                        if( *i != "")
                        {
                            std::cout<<it->first<<"   "<<*i<<std::endl;

                        }

                    }

            }
            /*

            for(auto l = lista.begin() ; l != lista.end() ; ++l)
            {
                for(auto it = struktura.begin() ; it != struktura.end() ; ++it)
                {
                    if( it->first == *l)
                    {
                        std::cout<<"yes"<<std::endl;
                        std::cout<<*l<<std::endl;

                    }
                }
            }
            
*/     
std::string name = "dwa.dot";
 Save_In_File2(struktura , name);



        }
void Save_In_File2(std::map<std::string, std::list<std::string>> l, std::string name)
        {
                    DODAWANIE();

            
            std::ofstream file(name);
            file << "digraph files_graph\n{\n";
            for (auto i = l.begin(); i != l.end(); ++i) 
            {
                
                    for(auto j=i->second.begin(); j!=i->second.end() ; ++j)
                    {


                        if( *j != "")
                        {
                            file<<i->first<<"->"<<*j<<std::endl;

                        }
                       


                    }
                 
            }

                file << "}";
                file.close();




                std::string word = "dot -Tpng -O dwa.dot";
                int n = word.length();
                char array[n+1];
                strcpy(array , word.c_str());

            exec(array);
            MAPA();

        }



        void Save_In_File(std::map<std::string, std::vector<std::pair<std::string,double>>> l,std::map<std::string, double> x , std::string name)
        {
                    DODAWANIE();

            
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
            MAPA();

        }

        std::string exec(const char* cmd) 
        {
            DODAWANIE();

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
            MAPA();

            return result;
        }


};


