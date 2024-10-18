#include <iostream>
#include <cstdbool>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <cmath>

bool checkArgCount (int argc) 
{
     if (argc != 2) 
          return false;
     return true;
}

bool checkNumber (char *input) 
{
     for (int i = 0; i < strlen(input); i++)
          if (!isdigit(input[i]))
               return false;
     return true;
}

bool checkPrime (int input) 
{
     if (input < 2)
          return false;
     for (int i = 2; i <= sqrt(input); i++)
          if (input % i == 0)
               return false;
     return true;
}

void processTest (int tempNumber)
 {
     pid_t pid = fork();
     if (pid > 0) 
     {
          wait(NULL);
          std::cout << "even number: " <<std::endl;
          for (int i = 0; i < tempNumber; i++) 
               if (i % 2 == 0)
                    std::cout << i << "\t";
     }
     if (pid == 0) 
     {
          std::cout << "odd number: " << std::endl;
          for (int i = 0; i < tempNumber; i++)
               if (i % 2 != 0)
                    std::cout <<  i << "\t";
          std::cout << std::endl;
     }
}

void processTest2 (int tempNumber) 
{
     pid_t pid = fork();
     if (pid > 0) 
     {
          int sum = 0;
          std::cout << "sum in range: ";
          for (int i = 0; i < tempNumber; i++) 
               sum += i;
          std::cout << sum << std::endl;
          wait(NULL);
     }
     if (pid == 0)
     {
          std::cout << "prime number: ";
          for (int i = 0; i < tempNumber; i++) 
               if (checkPrime(i))
                    std::cout << i << "\t";
          std::cout << std::endl;
     }
}

int main (int argc, char *argv[]) 
{
     int tempNumber;
     if (!checkArgCount(argc))
          std::cout << "something went wrong!" << std::endl;
     else 
     {
          for (int i = 1; i < argc; i++)
               if (checkNumber(argv[i])) {
                    tempNumber = atoi(argv[i]);
                    processTest(tempNumber);
                    sleep(5);
                    processTest2(tempNumber);
               }
     }

     return true;
}