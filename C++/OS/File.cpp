#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdbool>

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
     std::string tempString;
     tempString = static_cast<std::string>(input[1]);
     tempString.append(static_cast<std::string>(input[2]));
     if(!checkInputCount(argc))
          return false;
     for (int i = 1; i < argc; i++)
          if(checkExistFile(input[i]))
               if (tempString.find("input.txt") == std::string::npos || tempString.find("output.txt") == std::string::npos)
                    return false;
     return true;
}

void showFileInputContent (char *input) {
     std::string contentFile;
     std::ifstream fileInput;
     fileInput.open(input);
     if (fileInput.is_open()) {
          while( std::getline(fileInput, contentFile))
               std::cout << contentFile << std::endl;
          fileInput.close();
     }
}

int main (int argc, char *argv[]) 
{
     if (!checkInputHandler(argc, argv)) {
          std::cout << "error input" << std::endl;
          exit(1);
     }
     showFileInputContent(argv[1]);

     return true;
}