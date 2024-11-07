#include<iostream>
#include<cstdbool>
#include<cstring>
#include<fstream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

bool checkInput (int argc, char *input) 
{
     if (argc !=3)
          return false;
     int length = strlen(input);
     if (length < 20)
          return false;

     for (int i = 0; i < length; i++)
          if (!isdigit(input[i]))
               return false;
     return true;     
}

bool checkExistFile (char *file) 
{
     if (!std::ifstream (file))
          return false;
     return true;
}

std::string reverseInput (char *input) 
{
     std::string temp = "";
     for (int i = strlen(input) - 1; i >= 0; i--)
          temp += input[i];
     return temp;
} 

double sumNumber (std::string input) 
{
     double sum = 0;
     for (int i = 0; i < input.length(); i++)
     {
          char temp = input[i];
          sum += atoi(&temp);
     }
     return sum;
}

void showContentFile (char *fInput, int sum) 
{
     if (!checkExistFile(fInput))
     {
          std::cout << "file output not exist!" << std::endl;
          exit (false);
     }     
     else 
     {  
          std::string temp;
          std::ifstream file;
          file.open(fInput);
          while (file >> temp)
               std::cout << temp << std::endl;
          std::cout << "sum = " << sum << std::endl;
     }
}

void writeFile (char *fInput ,std::string input)
{
     std::ofstream file;
     file.open(fInput);
     if (!file.is_open())
     {
          std::cout << "error when open file output" << std::endl;
          return;
     }
     file << input;
     file.close();
}

void processTest (char *input, char* fInput)
 {
     pid_t pid = fork();
     if (pid > 0)
     {
          wait(nullptr);
          std::cout << "file content: " << std::endl;
          showContentFile(fInput, sumNumber(input));
     }
     else if (pid == 0)
          writeFile(fInput, reverseInput(input));
     else
     {
          std::cout << "something went wrong!" << std::endl;
          exit(false);
     }
}

int main (int argc, char *argv[]) 
{
     char* handler = argv[1];
     if (!checkInput(argc, argv[1]))
          std::cout << "your input is wrong!" << std::endl;
     processTest (argv[1], argv[2]);
     return true;
}