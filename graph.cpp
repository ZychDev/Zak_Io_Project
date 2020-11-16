#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"search_include.cpp"
#include<stdexcept>
#include<string>
#include<sstream>
#include<list>
#include<algorithm>
#include"search2.cpp"
#include<cstring>
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





            Save_In_File_Files(l,x,name);


        };

        Graph(std::map<std::string, std::list<std::string>> struktura)
        {
            
            
            
      
            std::string name = "dwa.dot";
            Save_In_File_Func(struktura , name);



        }

        Graph(std::map<std::string, std::vector<std::string>> names)
        {
            std::string name = "namespace.dot";
            Save_In_File_Namespac(name ,names);

        };



        void Save_In_File_Namespac(std::string name ,std::map<std::string, std::vector<std::string>> names )
        {
            std::ofstream file(name);
            file << "digraph files_graph\n{\n";

            for(auto it = names.begin() ; it != names.end() ; ++it)
            {
                for( auto j = it->second.begin() ; j != it->second.end() ; ++j)
                {
                    file<<it->first<<"->"<<*j<<std::endl;

                }
            }

            file << "}";
            file.close();


            std::string word = "dot -Tpng -O namespace.dot";
            int n = word.length();
            char array[26];
            strcpy(array , word.c_str());

            exec(array);

            MAPA();

        }

        void Save_In_File_Func(std::map<std::string, std::list<std::string>> l, std::string name)
        {
                    DODAWANIE();
                    //dodawanie();
            
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
                char array[20];
                strcpy(array , word.c_str());

            exec(array);

            MAPA();

        }



        void Save_In_File_Files(std::map<std::string, std::vector<std::pair<std::string,double>>> l,std::map<std::string, double> x , std::string name)
        {
            DODAWANIE();
            //dodawanie();
            
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
                char array[21];
                strcpy(array , word.c_str());

            exec(array);

            MAPA();
        }

    std::string exec(const char* cmd) 
    {
        DODAWANIE();
        //dodawanie();

        #ifdef _WIN32
        _popen(" ", "w");
        #else
        popen(" ", "w");
        #endif

        char buffer[128];
        std::string result = "";
        FILE* pipe = popen(cmd, "r");
        if (!pipe) throw std::runtime_error("fail");
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


