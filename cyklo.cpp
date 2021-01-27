#include <iostream>
#include <string>
#include <vector>
#include <fstream>
std::vector<std::string> cyklo(std::string name)
{
    std::vector<std::string> nazwy;



    system("touch bash");
    std::string cmd = "pmccabe -f ";
    cmd += name;
    std::string file_name = "bash";
    cmd+=" >> "+file_name;
    system(cmd.c_str());
    system("touch bash2");
    //system(">bash2");
    std::string cmd2 = "cat bash | sed 's/|/ /' | awk '{print $1, $7}' >> bash2";
    system(cmd2.c_str());
    system("cat bash");
    system("cat bash2");
    system(">bash");


    std::ifstream file("bash2");
    std::string line;
    while (std::getline(file, line))
    {
        nazwy.push_back(line);
    }
    

    return nazwy;
}