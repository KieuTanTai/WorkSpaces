#include <cstdlib>
#include <fstream>
<<<<<<< HEAD
#include <cstring>
#include <iostream>
#include <cstdbool>
=======
#include <string>
#include <iostream>
#include <cstdbool>
#include <sstream>
#include <cmath>
>>>>>>> Test

bool checkExistFile (char *input) 
{
     std::ifstream file (input);
     if (file) 
     {
          std::cout<< "file existed"<<std::endl;
          return true;
     }
     else 
     {
          std::cout<< "file not existed" << std::endl;
          return false;
     }
}

bool checkInputCount (int argc)
{
     if (argc !=3) 
          return false;
     return true;
}

bool checkInputHandler (int argc, char *input[]) 
{
<<<<<<< HEAD
     std::string tempString;
     tempString = static_cast<std::string>(input[1]);
     tempString.append(static_cast<std::string>(input[2]));
=======
     std::string inpString;
     inpString = static_cast<std::string>(input[1]);
     inpString.append(static_cast<std::string>(input[2]));
>>>>>>> Test
     if(!checkInputCount(argc))
          return false;
     for (int i = 1; i < argc; i++)
          if(checkExistFile(input[i]))
<<<<<<< HEAD
               if (tempString.find("input.txt") == std::string::npos || tempString.find("output.txt") == std::string::npos)
=======
               if (inpString.find("input.txt") == std::string::npos || inpString.find("output.txt") == std::string::npos)
>>>>>>> Test
                    return false;
     return true;
}

<<<<<<< HEAD
void showFileInputContent (char *input) {
=======
bool checkNumber (std::string input) 
{
     for (int i = 0; i < input.length(); i++) 
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
void showFileInputContent (char *input) 
{
>>>>>>> Test
     std::string contentFile;
     std::ifstream fileInput;
     fileInput.open(input);
     if (fileInput.is_open()) {
<<<<<<< HEAD
          while( std::getline(fileInput, contentFile))
=======
          while (std::getline(fileInput, contentFile))
>>>>>>> Test
               std::cout << contentFile << std::endl;
          fileInput.close();
     }
}

<<<<<<< HEAD
int main (int argc, char *argv[]) 
{
=======
int* calcSumInFile (char *input, int &index)
{
     int sum = 0; 
     int *numInFile = new int[index];
     index = 0;
     std::string fileValue;
     std::ifstream fileInput;
     fileInput.open(input);
     if (fileInput.is_open()) {
          while (std::getline(fileInput, fileValue)) 
          {
               std::stringstream ss(fileValue);
               std::string temp;
               while (std::getline(ss, temp,' '))
                    if (checkNumber(temp))
                    {
                         sum += atoi(temp.c_str());
                         numInFile[index] = atoi(temp.c_str());
                         index ++;
                    }
          }
          fileInput.close();
     }
     std::cout << "sum = " << sum << std::endl;
     return numInFile;
}

void writeOuput (char *input[], int index)
{
     int iPrime = 0;
     int *temp = calcSumInFile(input[1], index);
     int *primeArray = new int[iPrime];
     for (int i = 0; i < index; i++)
     {
          if (checkPrime(temp[i]))
          {
               primeArray[iPrime] = temp[i]; 
               iPrime ++;
          }
     }
     std::ofstream fileOut;
     fileOut.open(input[2]);
     if (fileOut.is_open()) {
          for (int i = 0; i < iPrime; i++) 
          {
               std::cout << primeArray[i] << std::endl;
               fileOut << primeArray[i] << "\t";
          }
          fileOut.close();
     }
     showFileInputContent (input[2]);
}

int main (int argc, char *argv[]) 
{
     int index;
>>>>>>> Test
     if (!checkInputHandler(argc, argv)) {
          std::cout << "error input" << std::endl;
          exit(1);
     }
<<<<<<< HEAD
     showFileInputContent(argv[1]);
=======
     showFileInputContent (argv[1]);
     writeOuput (argv, index);
>>>>>>> Test

     return true;
}