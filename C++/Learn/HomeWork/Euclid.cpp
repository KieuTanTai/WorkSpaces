#include <iostream>
#include <math.h>
#include <cstdlib>
int Euclid(int number_1, int number_2)
{
     while (number_1 != number_2)
     {
          if (number_1 > number_2)
          {
               number_1 = number_1 - number_2;
          }
          else
          {
               number_2 = number_2 - number_1;
          }
     }
     return number_2;
}
int Fibonacci_Number(int n)
{
     int f0 = 0;
     int f1 = 1;
     int f2 = 1;
     int i;
     if (n < 0)
     {
          return -1;
     }
     else if (n == 0 || n == 1 )
     {
          return n;
     }
     else
     {
          for(i = 2; i < n; i++)
          {
               f0 = f1;
               f1 = f2;
               f2 = f0 + f1;
          }
     }
     return f2;
}
int main()
{
     int A, B, end;
     std::cout<< " end = ";
     std::cin>>end;
     std::cout<<"number_A = ";
     std::cin>>A;
     std::cout<<"number_B = ";
     std::cin>>B;
     //std::cout<<"after Euclid function: "<< Euclid(A, B) << std::endl;
     for(int i = 0; i< end; i++)
     {
          std::cout<<Fibonacci_Number(i)<<" \t ";
     }
     return 0;
}