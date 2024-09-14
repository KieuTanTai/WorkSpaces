#include<iostream>
#include<cstring>
#include<sstream>
#include<cstdlib>
#include<climits>

int Cau2a1(std::string input)
{
     int count=0;
     std::string temp;
     std::stringstream ss(input);
     while(ss>>temp)
     {
          std::cout<< temp<<"\t";
          count++;
     }
     std::cout<<"so luong khoang trang: "<<count-1<<std::endl;
     return count-1;
}

int Cau2a2(std::string input)
{
     int spec_count=0;
     std::string temp;
     std::stringstream ss(input);
     while(ss>>temp)
     {
          std::cout<< temp<<"\t";
          for(int i=0; i<temp.length(); i++)
          {
               if(temp[i] == ',' || temp[i] == '.' || temp[i] == '?' || temp[i] == '!' || temp[i] == ':' || temp[i] == ';')
                    spec_count++;
          }
     }
     std::cout<<"so luong ky tu dac biet: "<<spec_count<<std::endl;
     return spec_count;
}

void Cau2b(std::string input)
{
     std::string temp;
     std::stringstream ss(input);
     while(ss>>temp)
          std::cout<<temp.length()<<"\t";
     std::cout<<std::endl;
}

int Cau2c(std::string input)
{
     std::string temp;
     std::string largest_char;
     int count_char = 0;
     int max = INT_MIN;
     std::stringstream ss(input);
     while(ss>>temp)
     {
          count_char=0;
          for(int i=0; i< temp.length(); i++)
          {
               count_char ++;
               if(temp[i] == ',' || temp[i] == '.' || temp[i] == '?' || temp[i] == '!' || temp[i] == ':' || temp[i] == ';')
                    count_char --;
          }
          if(count_char > max)
          {
               max = count_char;
               largest_char = temp;
          }
     }
     std::cout<<"ky tu co do dai lon nhat: "<<count_char<<std::endl;
     std::cout<<largest_char<<std::endl;
     return count_char;
}

int main(int argc, char *argv[])
{
     std::string input;
     std::cout<<"nhap chuoi string: ";
     std::getline(std::cin, input);
     std::cout<<std::endl;
     Cau2a1(input);
     Cau2a2(input);
     Cau2b(input);
     Cau2c(input);
     return 0;
}