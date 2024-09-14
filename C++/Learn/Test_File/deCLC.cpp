#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<fstream>
#include<climits>
//read string input
float dequy(int chieusau, float x)
{
     if(chieusau==1)
          return std::sqrt(x);
     return std::sqrt(x+dequy(chieusau-1, x));
}
float kodequy(int chieusau, float x)
{
     float temp=0;
     for(int i=0; i<chieusau; i++)
          temp=std::sqrt(x+temp);
     return temp;
}
void read_string(std::string input)
{
     int count;
     int temp_length=0;
     std::string largest;
     std::string temp;
     std::stringstream ss(input);
     while(ss>>temp)
     {
          count=0;
          for(int i=0; i<temp.length(); i++)
               count++;
          std::cout<<count<<"\t";
          if(temp_length < count)
          {
               temp_length = count;
               largest = temp;
          }
     }
     std::cout<<std::endl;
     std::cout<<"ky tu dai nhat: "<<largest<<std::endl;
}
//read file string
void read_file_string()
{
     int max = 0;
     std::string largest_string;
     std::string input;
     std::ifstream string_file;
     std::ofstream file_out;
     string_file.open("../../Documents/String.INP");
     file_out.open("../../Documents/string_out.txt");
     if(!string_file.is_open())
          return;
     if(!file_out.is_open())
          return;
     while(std::getline(string_file, input))
     {
          std::string temp, last_word;
          std::stringstream ss(input);
          // PHAI DAT max = 0 de ham so sanh hop le
          if(max < input.length())
          {
               max = input.length();
               largest_string = input;
          }
          //lap den tu cuoi cung cua dong
          while(ss>>temp)
               last_word = temp;
          //write last elements
          if(!last_word.empty())
               file_out<<last_word<<std::endl;
     }
     std::cout<<"chuoi ky tu dai nhat: "<<largest_string<<std::endl;
     file_out<<largest_string<<std::endl;
     string_file.close();
     file_out.close();
}
//read file number
bool prime_number(int n)
{
     if(n<2)
          return false;
     for(int i=2; i<=sqrt(n); i++)
          if(n%i == 0)
               return false;
     return true;
}
void read_file_number(int *&array, int &n)
{
     std::ifstream file_inp;
     file_inp.open("../../Documents/NUM.INP");
     if(!file_inp.is_open())
          return;
     file_inp>>n;
     array = new int[n];
     for(int i=0; i<n; i++)
          file_inp>>array[i];
     file_inp.close();
}

int Prime_N(int *array, int n)
{
     int count=0;
     for(int i=0; i<n; i++)
          if(prime_number(array[i]))
               count++;
     return count;
}
int *sort_file(int *array, int n)
{
     std::cout<<std::endl;
     for(int i=0; i<n-1; i++)
     {
          int temp = i;
          for(int j=i+1; j<n; j++)
               if(array[j] < array[temp])
                    temp =j;
          if(temp != i)
               std::swap(array[i], array[temp]);
     }
     return array;
}
void write_file(int *array, int n)
{
     int *temp_array = new int[n];
     temp_array = sort_file(array, n);
     std::ofstream file_out;
     file_out.open("../../Documents/NUM.OUT");
     if(!file_out.is_open())
          return;
     file_out<<Prime_N(array, n)<<std::endl;
     for(int i=0; i<n; i++)
          file_out<<temp_array[i]<<"\t";
     file_out.close();
}
int main()
{
     int *array;
     int n, chieusau;
     float x;
     std::string input;
     std::cout<<"nhap chuoi:";
     std::getline(std::cin, input);
     std::cout<<"x = ";
     std::cin>>x;
     std::cout<<"chieu sau = ";
     std::cin>>chieusau;
     std::cout<<"gia tri: "<<dequy(chieusau, x)<<std::endl;
     std::cout<<"gia tri khong de quy: "<<kodequy(chieusau, x)<<std::endl;
     read_string(input);
     read_file_string();
     read_file_number(array, n);
     write_file(array, n);
     return 0;
}