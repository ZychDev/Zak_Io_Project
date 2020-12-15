#include <iostream>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <filesystem>
#include <fstream>

#include <gtest/gtest.h>

std::map<std::string, double> listing();

bool dirExists(std::string c)
{
  struct stat info;
  const char * pathname = c.c_str();

  if (stat(pathname, &info) != 0)
  {
      printf("cannot access %s\n", pathname);
    return false;
  }
  else if (info.st_mode & S_IFDIR)
  { // S_ISDIR() doesn't exist on my windows
    printf("%s is a directory\n", pathname);
    return true;
  }
  else
  {
    printf("%s is no directory\n", pathname);
    return false;
  }
}

TEST(Sprawdzam_sciezke, czy_istnieje_w_aktualnym_folderze)
{

  std::string sciezka = ".";
  //std::cin>>sciezka;
  EXPECT_EQ(dirExists(sciezka) , true);

}

bool path_is_empty(std::string path)
{
	return std::filesystem::is_empty(path);
}

TEST(Sprawdam_sciezke , czy_folder_jest_pusty)
{
  std::string sciezka = "." ;
  //std::cin>>sciezka;
  EXPECT_EQ(path_is_empty(sciezka) , false);

}

bool compare_extension(char *filename, char *extension)
{
    /* Sanity checks */

    if(filename == NULL || extension == NULL)
        return false;

    if(strlen(filename) == 0 || strlen(extension) == 0)
        return false;

    if(strchr(filename, '.') == NULL || strchr(extension, '.') == NULL)
        return false;

    /* Iterate backwards through respective strings and compare each char one at a time */

    for(int i = 0; i < strlen(filename); i++)
    {
        if(tolower(filename[strlen(filename) - i - 1]) == tolower(extension[strlen(extension) - i - 1]))
        {
            if(i == strlen(extension) - 1)
                return true;
        } else
            break;
    }

    return false;
}

TEST(Sprawdzam_sciezke , czy_wyslalem_plik_cpp)
{
  //nazwa jaka wyslemy
  char filename[] = "max.xml";
  //to czego nie chcemy
  char extension[] = ".cpp";
  EXPECT_EQ( compare_extension(filename , extension)  ,  false );

    
}

bool sciezka_check(std::string name )
{
  std::ifstream ifs(name.c_str());
  if (!ifs)
  {
    return false;
  }
  else
  {
    return true;
  }
}

TEST(Sprawdzam_sciezke , czy_sciezka_istnieje)
{
  std::string sciezka = "/Users/szymon/Documents/AiSD/Final";
  EXPECT_EQ( sciezka_check(sciezka)  ,  true );

}

int main(int argc, char **argv) 
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

