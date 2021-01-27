#include <iostream>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
 
std::map<std::string, double> listing(std::string sciezka);
 
 
bool czy(std::string sciezka2, std::map<std::string, double> x){
  std::map<std::string, double> y = listing(sciezka2);
  if(x.size() != y.size()){
    return false;
  }
 
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
 
TEST(Sprawdzam_sciezke, czy_sciezka_istnieje){
  std::map<std::string, double> x;
  x["Mateusz_name_fun.cpp"] = 3182;
  x["aft2_loop.txt"] = 2138;
  x["convert.cpp"] = 730;
  x["files_functions_dep.cpp"] = 2228;
  x["graph.cpp"] = 9035;
  x["listing.cpp"] = 1334;
  x["main.cpp"] = 4838;
  x["paradigm.cpp"] = 6628;
  x["paradigm.xml"] = 34584;
  x["s_names_names.cpp"] = 2062;
  x["search_func_nam.cpp"] = 2659;
  x["search_include.cpp"] = 1249;
  x["search_namespace.cpp"] = 1614;
  x["start_xml.txt"] = 546;
  x["test.txt"] = 0;
  x["wersja_gita.cpp"] = 494;
  std::string sciezka = ".";
 
  EXPECT_TRUE(czy(sciezka, x));
  //EXPECT_EXIT(wrong_path(" "), ::testing::ExitedWithCode(-1), "Wrong path");
}
 
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}