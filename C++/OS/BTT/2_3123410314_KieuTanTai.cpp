#include<iostream>
#include<cstdlib>
#include<cstdbool>
#include<fstream>
#include<sstream>
#include<cstring>

bool checkNumber (std::string input) {
     for (int i = 0; i < input.length(); i++)
          if (!isdigit(input[i]))
               return false;
     return true;
}

bool checkTotalInput (int argc) 
{
     if (argc != 4)
          return false;
     return true;
}

bool checkFirstInput (char *input) 
{
     if ((atoi(input) < 0) || atoi(input) > 9)
          return false;
     return true;
}

bool checkExistFile (char *fInput) 
{
     std::ifstream file;
     file.open(fInput);
     if (!file.is_open())
          return false;
     else 
          file.close();
     return true;
}

void showContentFile (char *fInput, int count) 
{
     if (!checkExistFile(fInput))
     {
          std::cout << "file output not exist!" << std::endl;
          exit (false);
     }     
     else 
     {  
          int breakLine = 0;
          std::string temp;
          std::ifstream file;
          file.open(fInput);
          while (file >> temp)
          {
               if (breakLine %20 == 0)
                    std::cout << std::endl;
               std::cout << temp << "   ";
               breakLine ++;
          }
          std::cout << "\ntotal: " << count << std::endl;
     }
}

// sum elements in number
bool checkElements (std::string input, int inputValue) 
{
     for (int i = 0; i < input.length(); i++ )
     {
          char temp = input[i];
          if (atoi(&temp) == inputValue)
               return false;
     }
     return true;    
}

std::string getElementsOnFile (char *fInput, int inputValue, int &count) 
{
     std::string output = "";
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
          while (std::getline(file, temp))
          {
               if (!checkNumber(temp)) 
                    continue;
               if (checkElements(temp, inputValue))
               {
                    output += temp + " ";
                    count ++;
               }
          }
          file.close();
     }
     return output;
}

void writeFileOutput (char *fInput, std::string outputString) 
{
     std::string temp;
     std::ofstream fileOutput;
     fileOutput.open(fInput);
     if (!fileOutput.is_open()) 
     {
          std::cout << "error when create file or read file!" << std::endl;
          exit (false);
     }
     else 
          fileOutput << outputString;
     fileOutput.close();
}

int main (int argc, char *argv[]) 
{
     int count = 0;
     std::string outputString;
     if (!checkTotalInput(argc))
     {
          std::cout << "error input count!" << std::endl;    
          exit (false);
     } 
     if (!checkFirstInput(argv[1]) || !checkExistFile(argv[2]))
     {
          std::cout << "your input is not correct or input file not exist!" << std::endl;
          exit (false);
     }
     outputString = getElementsOnFile(argv[2], atoi(argv[1]), count);
     writeFileOutput(argv[3], outputString);
     showContentFile(argv[3], count);
     return true;
}