#include<iostream>
#include<stdbool.h>
#include <unistd.h>
#include <cstring>
#include<fstream>
#include <sys/types.h>
#include <sys/wait.h>
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

bool checkExist (char *input) 
{
     std::ifstream file;
     file.open(input);
     if (!file.is_open())
     {
          exit(2);
     }
     else 
          file.close();
     exit(0);
}

int main (int argc, char *argv[]) 
{
     if (!checkArgCount(argc))
          exit(false);
     int status;
     pid_t pid = fork();
     if (pid > 0) 
     {
          wait(&status);
          std::cout << status << std::endl;
     }
     else if (pid == 0)
     {
          status = checkExist (argv[1]);
          if(status)
          {
               WIFEXITED(status);
          }
     }
     return true;
}