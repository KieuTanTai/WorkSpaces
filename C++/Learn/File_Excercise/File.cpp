#include <iostream>
#include <fstream>
#include "../../Class/Functions_Header/Usually_Use.hpp"
//read file function
void read_file(int Number)
{
     std::ifstream file;
     file.open("../../Documents/NUM.INP");
     for(int i=0; i<Number; i++)
          std::cout<<file.get()<<"\t";
     file.close();
}
//write file function
void write_file(int Number)
{
     int count = 0;
     //create file input
     std::ofstream test_file ("../../Documents/NUM.INP");
     int *array = new int[Number];
     test_file<<Number<<std::endl;
     for(int i=0; i<Number; i++)
     {
          array[i] = random_Number(); //call functions from header file
          test_file<<array[i]<<"   ";
     }
     test_file.close();
     //write to file output
     std::ofstream file ("../../Documents/NUM.OUT");
     for(int i=0; i<Number; i++)
     {
          if(prime_Number(array[i])) //call functions from header file
               count++;
     }
     file<<count<<std::endl;
     heap_Sort(array, Number);
     for(int i=0; i<Number; i++)
     {
          file<<array[i]<<"   ";
     }
     file.close();
     delete[] array;
}
int main()
{
     int Number;
     std::cout<<"Enter the number of random numbers you want: ";
     std::cin>>Number;
     write_file(Number);
     read_file(Number);
     return 0;
}