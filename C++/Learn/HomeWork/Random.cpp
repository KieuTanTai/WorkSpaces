#include <iostream>
#include <random>
#include <ctime>

//random seed function
void random_seed()
{
     std::random_device RD_Number;
     //std::mt19937 gen(rd());
     std::uniform_int_distribution<int> dist(1,1000);
     for(int i = 0; i < dist(RD_Number); i++)
     {
          std::cout << dist(RD_Number) << " \t ";
     }
     std::cout << std::endl;
}
int main()
{
     random_seed();
     return 0;
}