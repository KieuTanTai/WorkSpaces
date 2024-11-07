#include<iostream>
#include<cstdbool>
#include<cstring>
#include<fstream>
#include<unistd.h>
#include<sys/time.h>
#include<sys/wait.h>
#include <climits>

bool checkInput (int argc, char *input) 
{
     if (argc !=2)
          return false;
     int length = strlen(input);
     for (int i = 0; i < length; i++)
          if (!isdigit(input[i]))
               return false;
     return true;     
}

void collatz (long long input) 
{
     long max = INT_MIN;
     while (input != 1)
     {
          if (max < input)
               max = input;
          if (input % 2 == 0)
               input = input/2;
          else
               input = 3 * input + 1;
          std::cout << input << "   ";
     }
     std::cout << "\nMax = " << max << std::endl;
}

void processTest (char *input, timeval tv)
 {
     pid_t pid = fork();
     if (pid > 0)
     {
          wait(nullptr);
          gettimeofday(&tv, NULL);
          double endTime = tv.tv_sec + (tv.tv_sec / 1000000) / 1000.0;
          std::cout << endTime << std::endl;
     }
     else if (pid == 0)
     {
          collatz(atoi(input));
     }
     else
     {
          std::cout << "something went wrong!" << std::endl;
          exit(false);
     }
}

int main (int argc, char *argv[]) 
{
     timeval start_time;
     timeval end_time;
     char* handler = argv[1];
     if (!checkInput(argc, argv[1]))
          std::cout << "your input is wrong!" << std::endl;
     processTest (argv[1], start_time);
     return true;
}