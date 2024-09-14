#include <iostream>
#include <math.h>
struct prime
{
     int N, TBC;
     int X, Y;
}Prime_Number;
bool prime_Number(int Number)
{
     if (Number < 2)
     {
          return false;
     }
     else
     {
          for(int i=2; i<sqrt(Number); i++)
          {
               if(Number%i == 0)
                    return false;
          }
     }
     return true;
}
int main()
{
     int count=0;
     std::cout<<"end = ";
     std::cin>>Prime_Number.X;
     for(int i = 1; i<=Prime_Number.X; i++)
     {
          if(prime_Number(i))
               count++;
     }
     std::cout<<"tu 1 den "<<Prime_Number.X<<" co "<<count<<" so nguyen to"<<std::endl;
     return 0;
}