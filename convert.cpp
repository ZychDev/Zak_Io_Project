#include<iostream>
#include<vector>
#include<map>
#include<list>

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

