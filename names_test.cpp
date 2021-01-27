#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include <string>
//#include "s_names_names.cpp"
std::vector<std::string> wyszukiwanie_name_ciag(std::map<std::string, double> pliki);

bool same_names(std::string sciezka, std::map<std::string, std::vector<std::string>> map){
    std::map<std::string, std::vector<std::string>> map2;
    if(map == map2){
        return true;
    }
    else return false;
}

TEST(szukanie_namespace, dependencies){
    std::vector<std::string> wyszukiwanie_name_ciag(std::map<std::string, double> pliki){
        std::map<std::string, std::vector<std::string>> mapa;   
        mapa["testing"] = "InitGoogleTest(&argc, argv);";
        mapa["test"] = "show_me();";
        mapa["trzy"] = "wyswietl();";
        mapa["jeden"];
        mapa["dwa"] = "wyswietl2();";
        mapa["trzy"] = "wyswietl();";
        mapa["testing"] = "InitGoogleTest(&argv, argc);";
        std::string sciezka = ".";
    
        EXPECT_TRUE(same_names(sciezka, mapa));
    }
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}