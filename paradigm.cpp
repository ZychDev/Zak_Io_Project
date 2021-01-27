#include<iostream>
#include<string>
#include<map>
#include<vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h> 
//#include"start_xml.txt"
class paradigm_graph
{
  private:
    //wspolrzedne plikow 
    std::vector<std::pair<int , int>> para_shapes;
    std::vector<std::pair<int , int>> para_conns;
    std::vector<std::pair<std::string , std::string>> para_loop3;
    std::vector<std::pair<std::string , std::string>> f2;
    std::map<std::string , std::vector<std::pair<int,int>>> f3;
    std::map< std::string, std::map<std::string, std::pair<int , int>> > f4;


  std::string aft1_loop = "</ModelChildren></ModelRelationshipContainer></ModelChildren></ModelRelationshipContainer>";
  
  std::string aft3_loop= " </Shapes><Connectors>";

  std::string ending = "		</Connectors></UseCaseDiagram></Diagrams></Project>";;
  public:

    paradigm_graph()
    {
      //przypisanie wspolrzednych do shapes
      para_shapes.push_back(std::make_pair(779,225));
      para_shapes.push_back(std::make_pair(610,362));
      para_shapes.push_back(std::make_pair(317,317));
      para_shapes.push_back(std::make_pair(494,239));
      para_shapes.push_back(std::make_pair(238,145));
      para_shapes.push_back(std::make_pair(500,9)); 
      
      //przypisanie wspolrzednych do conns
      para_conns.push_back(std::make_pair(393,84));
      para_conns.push_back(std::make_pair(517,149));
      para_conns.push_back(std::make_pair(427,173));
      para_conns.push_back(std::make_pair(282,252));
      para_conns.push_back(std::make_pair(600,180));
      para_conns.push_back(std::make_pair(485,359));
      para_conns.push_back(std::make_pair(552,318));
      para_conns.push_back(std::make_pair(722,301));
      //FOR NR 1 stringi 
      f2.push_back(std::make_pair("s2","si"));
      f2.push_back(std::make_pair("s2","li"));
      f2.push_back(std::make_pair("s2","gr"));
      f2.push_back(std::make_pair("si","gr"));
      f2.push_back(std::make_pair("s2","mn"));
      f2.push_back(std::make_pair("gr","mn"));
      f2.push_back(std::make_pair("li","mn"));
      f2.push_back(std::make_pair("s3","mn"));

      //FOR 3 
      para_loop3.push_back(std::make_pair("s2","search2.cpp 1758 B"));
      para_loop3.push_back(std::make_pair("si","search_include.cpp 1619 B"));
      para_loop3.push_back(std::make_pair("li","listing.cpp 1218 B"));
      para_loop3.push_back(std::make_pair("gr","graph.cpp 5059 B"));
      para_loop3.push_back(std::make_pair("mn","main.cpp 1696 B"));
      para_loop3.push_back(std::make_pair("s3","search3.cpp 1265 B"));

      f3["s2"].push_back(std::make_pair(500,9));
      f3["s3"].push_back(std::make_pair(779,225));
      f3["mn"].push_back(std::make_pair(610,362));
      f3["gr"].push_back(std::make_pair(317,317));
      f3["li"].push_back(std::make_pair(494,239));
      f3["si"].push_back(std::make_pair(238,145));

      //FOR4
      f4["s2"].insert(std::make_pair("si", std::make_pair(393,84)));
      f4["s2"].insert(std::make_pair("li", std::make_pair(517,149)));
      f4["s2"].insert(std::make_pair("gr", std::make_pair(427,173)));
      f4["si"].insert(std::make_pair("gr", std::make_pair(282,252)));
      f4["s2"].insert(std::make_pair("mn", std::make_pair(600,180)));
      f4["gr"].insert(std::make_pair("mn", std::make_pair(485,359)));
      f4["li"].insert(std::make_pair("mn", std::make_pair(552,318)));
      f4["s3"].insert(std::make_pair("mn", std::make_pair(722,301)));
      

      //potrzebne wartosci dynamiczne
      std::string id = "ID";
      std::string id_2 = "ID_2";
      std::string c_counter = "c1";
      std::string name = "NAME";
      std::string name_combo = "NAME_NAME";

      //tworzenie pliku
      std::fstream file;
      std::ifstream ifile("start_xml.txt",std::ios::in);
      std::ofstream ofile("paradigm.xml",std::ios_base::app);
      if (!ifile.is_open()) 
      { 
        std::cout<<"file not found"; 
      } 
      else 
      { 
        ofile<<ifile.rdbuf(); 
      } 
      std::string word; 
      file.open("file2.txt"); 
      while (file >> word) 
      { 
      std::cout << word << " "; 
      }     
      
          
for(int i = 0; i < f2.size(); i++)
{
ofile<<"<Include  From=\""<<f2[i].first<<"\" Id=\""<<f2[i].first<<"_"<<f2[i].second<<"\" Name=\"1\" To=\""<<f2[i].second<<"\">"<<std::endl<<"<Stereotypes>"<<std::endl<<"<Stereotype Idref=\"inc\" Name=\"Include\"/>"<<std::endl<<"</Stereotypes>"<<std::endl<<"<MasterView>"<<std::endl<<"<Include Idref=\"c"<<i<<"\" Name=\"1\"/>"<<std::endl<<"</MasterView>"<<std::endl<<"</Include>"<<std::endl;
}
ofile<<aft1_loop<<std::endl;
  
for(int i = 0; i < para_loop3.size(); i++)
{
ofile<<"<UseCase  Id=\""<<para_loop3[i].first<<"\" Name=\""<<para_loop3[i].second<<"\" >"<<std::endl<<"</UseCase>"<<std::endl;
}

std::ifstream cfile("aft2_loop.txt",std::ios::in);
      if (!cfile.is_open()) 
      { 
        std::cout<<"file not found"; 
      } 
      else 
      { 
        ofile<<cfile.rdbuf(); 
      } 
      while (file >> word) 
      { 
      std::cout << word << " "; 
      }   

    ofile<<std::endl;

    for(auto i = f3.begin() ; i != f3.end() ; ++i)
    {
        for(auto j = i->second.begin() ; j != i->second.end() ; ++j)
        {
            
           ofile<<"<UseCase Background=\"rgb(122, 207, 245)\" Height=\"60\" Id=\""<<i->first<<"_s"<<"\" Model=\""<<i->first<<"\" Width=\"150\" X=\""<<j->first<<"\" Y=\""<<j->second<<"\">"<<std::endl
            <<"<ElementFont Color=\"rgb(0, 0, 0)\" Name=\"Dialog\" Size=\"11\" Style=\"0\"/>"<<std::endl
            <<"<Caption Height=\"80\" Visible=\"true\" Width=\"150\" X=\"0\" Y=\"0\"/>"<<std::endl
            <<"<FillColor Color=\"rgb(122, 207, 245)\" Style=\"1\" Transparency=\"0\" Type=\"1\"/>"<<std::endl
            <<"</UseCase>"<<std::endl;


        }
    }

ofile<<aft3_loop<<std::endl;

   

 int n = 0;
    for(auto i = f4.begin() ; i != f4.end() ; ++i)
    {
       
        for(auto j = i->second.begin() ; j != i->second.end() ; ++j)
        {
    
          ofile<<"<Include Background=\"rgb(122, 207, 245)\" Foreground=\"rgb(0, 0, 0)\" From=\""<<i->first<<"_s"<<"\" Id=\""<<"c"<<n<<"\" Model=\""<<i->first<<"_"<<j->first<<"\" To=\""<<j->first<<"_s\">"<<std::endl<<"<ElementFont Color=\"rgb(0, 0, 0)\" Name=\"Dialog\" Size=\"11\" Style=\"0\"/>"<<std::endl<<"<Caption Height=\"30\" Visible=\"true\" Width=\"82\" X=\"\" Y=\"\"/>"<<std::endl<<"</Include>"<<std::endl;
          n++;
        }
       
    }
  ofile<<ending;
  
  

};








/*4 for  done
std::cout<<"<Include Background=\"rgb(122, 207, 245)\" Foreground=\"rgb(0, 0, 0)\" From=\"\" Id=\"\" Model=\"\" To=\" \">"<<std::endl;
std::cout<<"<ElementFont Color=\"rgb(0, 0, 0)\" Name=\"Dialog\" Size=\"11\" Style=\"0\"/>"<<std::endl;
std::cout<<"<Caption Height=\"30\" Visible=\"true\" Width=\"82\" X=\"\" Y=\"\"/>"<<std::endl;
std::cout<<"</Include>"<<std::endl;

*/

};














