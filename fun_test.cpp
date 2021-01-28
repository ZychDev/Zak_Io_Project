#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<string>
#include<gtest/gtest.h>
//#include "search_func_nam.cpp"
#include "listing.cpp"

std::map<std::string, double> listing(std::string sciezka);
std::map<std::string, std::vector<std::string>> wyszukiwanie2(std::map<std::string, double> pliki);

bool te_same_wyniki(std::string sciezka2, std::map<std::string, double> x){
    std::map<std::string, double> y=listing(sciezka2);
    
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
    
    x["FileExists"];
    x["Graph"];
    x["Save_File_Bezposrednie"];
    x["Save_File_Func"];
    x["Save_File_n"];
    x["Save_In_File_Files"];
    x["Save_In_File_Func"];
    x["Save_In_File_Namespac"];
    x["exec"];
    x["fileExists"];
    x["function_namespce_functions"];
    x["git_version"];
    x["listing"];
    x["main"];
    x["map_second_element_on_list_string"];
    x["map_string_double_TO_string"];
    x["pliki_fun"];
    x["te_same_wyniki"];
    x["wyszukiwanie"];
    x["wyszukiwanie2"];
    x["wyszukiwanie_name"];
    x["wyszukiwanie_name_ciag"];
    std::string sc = ".";
    EXPECT_TRUE(te_same_wyniki(sc, x));
    //ASSERT_EXIT(wrong_path(" "), testing::ExitedWithCode(‑1), "Wrong path");
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}