#include<iostream>
#include<climits>
#include<sstream>
#include<cstring>
#include<fstream>
#include<cmath>
#include<algorithm>
//BT De Quy
// float DeQuy(int n)
// {
//      if(n==0)
//           return 1;
//      return (1/2.0)*DeQuy(n-1);
// }
// float KoDeQuy(int n)
// {
//      float An=1;
//      if(n==0)
//           return An;
//      while(n>0)
//      {
//           An*=(1/2.0);
//           n--;
//      }
//      return An;
// }
// float TongS(int n)
// {
//      float SumS=1;
//      for(int i=1; i<=n; i++)
//           SumS+=DeQuy(i);
//      return SumS;
// }
// int main()
// {
//      int n;
//      std::cout<<"n=";
//      std::cin>>n;
//      std::cout<<DeQuy(n)<<std::endl;
//      std::cout<<KoDeQuy(n)<<std::endl;
//      std::cout<<TongS(n)<<std::endl;
//      return 0;
// }

//string 
// int main()
// {
//      std::string temp;
//      int count=0, max = INT_MIN;
//      std::string s = "java was originally developed by James Gosling at sun microsystems";
//      std::stringstream ss(s);
//      while(ss>>temp)
//      {
//           for(int i=0; i<temp.length(); i++)
//           {
//                count++;
//           }
//           if(count > max)
//                max = count;
//           std::cout<<"count = "<<count<<std::endl;
//           std::cout<<"max = "<<max<<std::endl;
//           std::cout<<"temp = "<<temp<<std::endl;
//           count = 0;
//      }
//      return 0;
// }

//file

void readMatrix(const std::string &filename, int &n, int **&matrix) {
    std::ifstream file("../../Documents/table.inp");
    if (!file.is_open()) {
        std::cerr << "Không thể mở file " << filename << std::endl;
        return;
    }
    file >> n;
    matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void sortMatrixByRowSum(int **matrix, int n) {
    int *temp_array = new int[n];
    int *indices = new int[n];

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
        temp_array[i] = sum;
        indices[i] = i; // Lưu chỉ số dòng
    }

    // Sắp xếp temp_array và indices theo thứ tự giảm dần của temp_array
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (temp_array[i] < temp_array[j]) {
                std::swap(temp_array[i], temp_array[j]);
                std::swap(indices[i], indices[j]);
            }
        }
    }

    // In các dòng theo thứ tự đã sắp xếp
    for (int i = 0; i < n; ++i) {
        int index = indices[i];
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[index][j] << " ";
        }
        std::cout << std::endl;
    }

    delete[] temp_array;
    delete[] indices;
}

// int main() {
//     int n;
//     int **matrix;
//     std::string filename = "table.txt";

//     readMatrix(filename, n, matrix);

//     std::cout << "Ma trận đã đọc từ file:" << std::endl;
//     printMatrix(matrix, n);

//     std::cout << "\nSắp xếp các dòng theo thứ tự tổng giảm dần:" << std::endl;
//     sortMatrixByRowSum(matrix, n);

//     freeMatrix(matrix, n);

//     return 0;
// }



void write_file()
{
     std::string documents;
     std::ifstream file_inp;
     file_inp.open("../../Documents/String.INP");
     if(!file_inp.is_open())
     {
          std::cerr<<"error!"<<std::endl;
          return;
     }
     std::ofstream file_out;
     file_out.open("../../Documents/String.OUT");
     if(!file_out.is_open())
     {
          std::cerr<<"error!"<<std::endl;
          return;
     }
     while(std::getline(file_inp, documents))
     {
          std::stringstream ss(documents);
          std::string first_element;
          if(ss>>first_element)
          {
               file_out<<first_element<<std::endl;
               std::cout<<first_element<<std::endl;
          }
     }
     file_inp.close();
     file_out.close();
}

// int **array(int Row, int Column, int elements)
// {
//      int **array2D=new int *[Row];
//      for(int i=0; i<Row; i++)
//      {
//           array2D[i] = new int [Column];
//           for(int j=0; j<Column; j++)
//           {
//                array
//           }
//      }
// }

//read file input and write element in this file 
void read_file(int **&array, int &number)
{
     array=new int *[number];
     std::ifstream file_inp;
     file_inp.open("../../Documents/table.inp");
     file_inp>>number; //lay gia tri n tu file ra bien
     for(int i=0; i<number; i++)//lay gia tri matrix tu file ra mang dong
     {
          array[i]=new int[number];
          for(int j=0; j<number; j++)
          {
               file_inp>>array[i][j];
          }
     }
     file_inp.close();
     std::cout<<number<<std::endl;
     for(int i=0; i<number; i++)
     {
          for(int j=0; j<number; j++)
               std::cout<<array[i][j]<<"\t";
          std::cout<<std::endl;
     }
}
//sum elements in columns
int sum_cols(int **array, int number, int index)
{
     int *sum_array=new int[number];
     for(int i=0; i<number; i++)
     {
          int sum=0;
          for(int j=0; j< number; j++)
               sum+=array[i][j];
          sum_array[i] = sum;
     }
     return sum_array[index];
}
//kiem tra doi xung
int DoiXung(int **array, int number)
{
     int temp;
     for(int i=0; i<number; i++)
     {
          for(int j=0; j<number; j++)
               if(array[i][j] != array[j][i])
                    temp = 0;
               else
                    temp = 1;
     }
     return temp;
}
//xep tong phan tu tung dong theo thu tu giam dan
int sort_sum(int **array, int number, int index)
{
     int *temp_array= new int[number];
     int pos[number];
     for(int i=0; i<number; i++)
     {
          int sum=0;
          for(int j=0; j<number; j++)
               sum+=array[i][j];
          temp_array[i] = sum;
          pos[i]=i+1; //de cho index chay tu 1
     }
     for(int j=0; j<number-1; j++)
     {
          for(int g=number-1; g>j; g--)
          {
               if(temp_array[g]>temp_array[g-1])
               {
                    std::swap(temp_array[g], temp_array[g-1]);
                    std::swap(pos[g], pos[g-1]);
               }
          }
     }
     return pos[index];
}
void write_output(int **array, int number)
{
     std::ofstream file_out;
     file_out.open("../../Documents/result.txt");
     for(int i=0; i<number; i++)
          file_out<<sum_cols(array, number, i)<<"\t";
     file_out<<std::endl;
     file_out<<DoiXung(array, number)<<std::endl;
     for(int i=0; i<number; i++)
          file_out<<sort_sum(array, number, i)<<"\t";
     file_out<<std::endl;
     file_out.close();
}
int main()
{
     int **array;
     int number=6;
     write_file();
     read_file(array, number);
     write_output(array, number);
     delete []array;
     return 0;
}
