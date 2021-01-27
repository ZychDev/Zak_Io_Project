#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<string>
#include<gtest/gtest.h>
#include "search_func_nam.cpp"
#include "listing.cpp"

std::map<std::string, double> listing(std::string sciezka);
std::map<std::string, std::vector<std::string>> wyszukiwanie2(std::map<std::string, double> pliki);

bool te_same_wyniki(std::string sciezka2, std::map<std::string, double> x){
    std::map<std::string, double> y=listing(sciezka2);
    //std::map<std::string, std::vector<std::string>> y = wyszukiwanie2(sciezka2);
    if(x == y){
        return true;
    }
    else return false;
}
void wrong_path(std::string sciezka){
    if(sciezka==" "){
        std::cout<<"Wrong path"<<std::endl;
        exit(-1);
    }
}

TEST(szukanie_funkcji, czy_istnieje_funkcja){
    std::map<std::string, double> x;
    std::map<std::string, std::vector<std::string>> z = wyszukiwanie2(x);
    
    z["EXPECT_EQ"];
    z["FileExists"];
    z["Graph"];
    z["Save_File_Func"];
    z["Save_File_n"];
    z["Save_In_File_Files"];
    z["Save_In_File_Func"];
    z["Save_In_File_Namespac"];
    z["TEST"];
    z["czy"];
    z["exec"];
    z["fileExists"];
    z["function_namespce_functions"];
    z["listing"];
    z["main"];
    z["map_second_element_on_list_string"];
    z["map_string_double_TO_string"];
    z["pliki_fun"];
    z["te_same_wyniki"];
    z["wyszukiwanie"];
    z["wyszukiwanie2"];
    z["wyszukiwanie_name"];
    z["wyszukiwanie_name_ciag"];
    std::string sc = ".";
    EXPECT_TRUE(te_same_wyniki(sc, z));
    ASSERT_EXIT(wrong_path(" "), ::testing::ExitedWithCode(‑1), "Wrong path");
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
