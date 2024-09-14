#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cmath>
//read file table.inp
void Read_File(int **&array, int &row, int &column)
{
     std::ifstream file_inp;
     file_inp.open("../../Documents/table.inp");
     if(!file_inp.is_open())
     {
          std::cout<<"mo that bai" <<std::endl;
          return;
     }
     file_inp>>row;
     file_inp>>column;
     array = new int*[row];
     for(int i=0; i<row; i++)
     {
          array[i] = new int[column];
          for(int j=0; j<column; j++)
          {
               file_inp>>array[i][j];
          }
     }
     file_inp.close();
}
//cau A square table
int Square_Number(int **array, int row, int column)
{
     int count=0;
     for(int i=0; i<row; i++)
     {
          for(int j=0; j<column; j++)
          {
               int sqrtN = sqrt(array[i][j]);
               if(sqrtN*sqrtN == array[i][j])
                    count++;

          }
     }
     return count;
}
void Square_Table(int **array, int row, int column)
{
     int temp = Square_Number(array, row, column);
     std::ofstream square_file;
     square_file.open("../../Documents/square_file.txt");
     if(!square_file.is_open())
          return;
     square_file<<temp<<std::endl;
     for(int i=0; i<row; i++)
     {
          for(int j=0; j<column; j++)
          {
               int sqrtN= sqrt(array[i][j]);
               if(sqrtN * sqrtN == array[i][j])
                    square_file<<array[i][j]<<"\t"<<i+1<<"\t"<<j+1<<"\t"<<std::endl;
          }
     }
     square_file.close();
}
//odd number in file
int Odd_Number(int **array, int row, int column)
{
     int count=0;
     for(int i=0; i<row; i++)
          for(int j=0; j<column; j++)
               if(array[i][j] % 2 != 0)
                    count++;
     return count;
}
int Even_Number(int **array, int row, int column)
{
     int count=0;
     for(int i=0; i<row; i++)
          for(int j=0; j<column; j++)
               if(array[i][j] % 2 == 0)
                    count++;
     return count;
}
void Odd_Even_File(int **array, int row, int column)
{
     std::ofstream oddeven_file;
     oddeven_file.open("../../Documents/oddeven_file.txt");
     //check if file's not open
     if(!oddeven_file.is_open())
          return;
     int count_odd = Odd_Number(array, row, column);
     int count_even = Even_Number(array, row, column);
     oddeven_file<<count_odd<<std::endl;
     //write all odd numbers to this file
     for(int i=0; i<row; i++)
          for(int j=0; j<column; j++)
               if(array[i][j] % 2 != 0)
                    oddeven_file<<array[i][j]<<"\t";
     std::cout<<std::endl;
     oddeven_file<<count_even<<std::endl;
     //write all even numbers to this file
     for(int i=0; i<row; i++)
          for(int j=0; j<column; j++)
               if(array[i][j] % 2 == 0)
                    oddeven_file<<array[i][j]<<"\t";
     std::cout<<std::endl;
     oddeven_file.close();
}
//sort array_file
void Sort_Array(int **array, int row, int column)
{
     std::ofstream sort_file;
     sort_file.open("../../Documents/sort_file.txt");
     if(!sort_file.is_open())
          return;
     sort_file<<row<<"\t"<<column<<std::endl;
     //sort array
     for(int j=0; j<column; j++)
     {
          int *temp = new int[row];
          for(int i=0; i<row; i++)
          {
               std::cout<<array[i][j]<<"\t";
               temp[i] = array[i][j];
          }
          std::cout<<std::endl;
          std::sort(temp, temp+row);
          for(int i=0; i<row; i++)
               array[i][j] = temp[i];
          delete []temp;
     }
     std::cout<<"ma tran da duoc sap xep"<<std::endl;
     for(int i=0; i< row; i++)
     {
          for(int j=0; j<column; j++)
          {
               sort_file<<array[i][j]<<"\t";
               std::cout<<array[i][j]<<"\t";
          }
          std::cout<<std::endl;
          sort_file<<std::endl;
     }
     sort_file.close();
}
int main()
{
     int row, column;
     int **array;
     Read_File(array, row, column);
     Square_Table(array, row, column);
     Odd_Even_File(array, row, column);
     Sort_Array(array, row, column);
     delete []array;
     return 0;
}