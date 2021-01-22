#include<iostream>
#include<fstream>

void function_namespce_functions()
{
    std::string name = "listing.cpp";

    std::ifstream file(name);
    if(file.is_open())
    {
        std::string line;
        std::string search = "listing"; // najpierw szukam nazwy funkcji
        while(std::getline(file,line))
        {
            //printf("%s" , line.c_str());
            size_t miejsce = line.find(search);
            if (miejsce != std::string::npos)
            {
                std::cout<<"Znalazlem Funckje: "<<line<< std::endl;

                //teraz chce liczyc otwarcia funkcji 
                int counter_open = 0;
                int counter_close = 0;

                std::string search2 = "{";
                while(std::getline(file,line))
                {
                    size_t miejsce2 = line.find(search2);
                    if(miejsce2 != std::string::npos)
                    {
                        ++counter_open;
                        std::cout<<"Znalazlem Otwarcie: "<<line<<std::endl; 

                        //znalazlem otwarcie wiec przeszukam je w poszukiwaniu names
                        std::string search3 = "test";
                        while(std::getline(file,line))
                        {
                            size_t miejsce3 = line.find(search3);
                            if(miejsce3 != std::string::npos )
                            {
                                if(line == "}")
                                {
                                    
                                }
                            }
                        }
                    }


                }
            }

        }

        file.close();

    }
}



