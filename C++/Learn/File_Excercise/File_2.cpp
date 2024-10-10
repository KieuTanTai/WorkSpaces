#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../../Class/Functions_Header/Usually_Use.hpp"

void Read_File(int Row, int Column)
{
     //read file table.inp
     std::ifstream file;
     file.open("../../Documents/table.inp");
     if(file.is_open()) {
          for(int i=0; i<Row; i++)
          {
               for(int j=0; j<Column; j++)
                    std::cout<<file.get()<<"\t";
          }
          file.close();
     }
}
void Write_File(int &Row, int &Column)
{
     //create file table.inp
     std::ofstream file;
     file.open("../../Documents/table.inp");
     int **array = new int*[Row];
     file<<Row<<" "<<Column<<std::endl;
     for(int i=0; i<Row; i++)
     {
          array[i] = new int[Column];
          for(int j=0; j<Column; j++)
          {
               array[i][j]=random_Number();
               file<<array[i][j]<<"   ";
          }
          file<<std::endl;
     }
     file.close();
     std::ofstream file_out;
     file_out.open("../../Documents/table.out");
     //search max element and others same max element;
     Search_Max(file_out, Row, Column, array);
     //Summary elements in Columns
     for(int j=0; j<Column; j++)
     {
          int Sum_Column=0;
          for(int i=0; i<Row; i++)
          {
               Sum_Column+=array[i][j];
          }
          file_out<<Sum_Column<<" ";
     }
     file_out<<std::endl;
     array_2x2(file_out, Row, Column, array);
     delete []array;
     file_out.close();
}

int main()
{
     int Row=0, Column=0;
     while((Row <= 0||Row > 200) || (Column <= 0||Column > 200))
     {
          system("clear");
          std::cout<<"Row= ";
          std::cin>>Row;
          std::cout<<"Column= ";
          std::cin>>Column;
     }
     std::cout<<std::endl;
     Write_File(Row, Column);
     Read_File(Row, Column);
     return 0;
}