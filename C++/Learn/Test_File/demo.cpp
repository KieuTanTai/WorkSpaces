#include <iostream>
#include <algorithm>
#include <fstream>
int dequy(int n)
{
     int sum=0;
     if(n==1)
          return 1;
     for(int i=1; i<n; i++)
          sum+=dequy(i);
     return n+sum;
}
int kodequy(int n)
{
     int current=1;
     int sum=1; //dung de giu gia tri Xn-1
     for(int i=2; i<=n; i++) //i=2 tranh viec: n=1=true => sai ket qua
     {
          current=i+sum;
          sum+=current;
     }
     return current;
}
int Factorials(int n)
{
     if(n==1)
          return 1;
     return n * Factorials(n-1);
}
int Non_Recursive_Factorials(int n)
{
     int giaithua=1;
     for(int i=1; i<=n; i++)
     {
          giaithua*=i;
     }
     return giaithua;
}
int array(int arr[], int n)
{
     if(n==1)
          return arr[0];
     return arr[0] + array(arr+1, n-1);//tinh phan tu ke tiep arr+1
}
int main(int argc, char *argv[])
{
     int n;
     std::cout<<"n = ";
     std::cin>>n;
     int arr[n];
     for(int i=0; i<n; i++)
          std::cin>>arr[i];
     std::cout<<"Xn bang de quy: "<<dequy(n)<<std::endl;
     std::cout<<"Xn khong bang de quy: "<<kodequy(n)<<std::endl;
     std::cout<<"Giai thua bang de quy: "<<Factorials(n)<<std::endl;
     std::cout<<"Giai thua ko bang de quy: "<<Non_Recursive_Factorials(n)<<std::endl;
     std::cout<<"tong phan tu mang: "<<array(arr, n)<<std::endl;
     return 0;
}