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
 
TEST(Sprawdzam_sciezke, czy_sciezka_istnieje){
  std::map<std::string, double> x;
  x["Mateusz_name_fun.cpp"] = 3524;
  x["convert.cpp"] = 730;
  x["file_test.cpp"] = 1186;
  x["files_functions_dep.cpp"] = 2228;
  x["fun_test.cpp"] = 888;
  x["graph.cpp"] = 7862;
  x["listing.cpp"] = 1286;
  x["main.cpp"] = 4891;
  x["names_test.cpp"] = 969;
  x["s_names_names.cpp"] = 2063;
  x["search_func_nam.cpp"] = 2659;
  x["search_include.cpp"] = 1249;
  x["search_namespace.cpp"] = 1572;
  std::string sciezka = ".";
 
  EXPECT_TRUE(czy(sciezka, x));
  EXPECT_EXIT(nullptr, ::testing::ExitedWithCode(-1), "Wrong path");
}
 
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}