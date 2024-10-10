#include <cstring>
#include <climits>
#include <sstream>
#include <iostream>
#include <cstdbool>

bool checkInput (char *input) 
{
     for (int i = 0; i < strlen(input); i++)
          if (!isdigit(input[i]))
               return false;
     return true;
}

void isBiggest (int argc, char *input[]) 
{
     double max = INT_MIN;
     for (int i = 1; i < argc; i++)
          if (checkInput(input[i])) 
               if (max < atof(input[i]))
                    max = atof(input[i]);
     std::cout << "biggest number in this array is: " << max << std::endl;
}

void isSmallest (int argc, char *input[]) 
{
     double min = INT_MAX;
     for (int i = 1; i < argc; i++)
          if (checkInput(input[i]))
               if (min > atof(input[i])) 
                    min = atof(input[i]);
     std::cout << "smallest number in array is: " << min << std::endl;
}

void isAverage (int argc, char *input[]) 
{
     double sum = 0, average;
     for (int i = 1; i < argc; i++)
          if (checkInput(input[i])) 
               sum += atof(input[i]);
     if (argc > 1) 
     {
          average = static_cast<double>(sum) / (argc - 1);
          std::cout << "average = " << average << std::endl;
     }
     else 
     {
          std::cout << "you don't have any number!" << std::endl;
     }
}

void sumRange (char *input) 
{
     long sum = 0;
     if (checkInput(input))
          for (int i = 0; i < atol(input); i++)
               sum += i;
     std::cout << "sum in range: " << sum << std:: endl;
}

void sumNumInput(char *input)
{
     long long sum = 0;
     if (checkInput(input)) 
     {
          long long tempInput;
          std::stringstream ss(input);
          while (ss >> tempInput);
          while (tempInput > 0) 
          {
               sum += tempInput % 10;
               tempInput = tempInput / 10;
          }
          std::cout << "sum element in number : " << sum << std::endl;
     }
     return;
}

// int sumNumInString(std::string input) 
// {
//      int sum = 0;
//      std::stringstream ss(input);
//      std::string temp;
//      while(ss >> temp) 
//      {
//           try 
//           {
//                sum += stoi(temp);
//           } catch (std::exception &e) 
//           {
//                std::cerr<<e.what() << std::endl;
//           }
//      }
//      return sum;
// }

int main(int argc, char *argv[]) 
{ 
     isBiggest (argc, argv);
     isSmallest (argc, argv);
     isAverage (argc, argv);
     sumRange (argv[1]);
     sumNumInput (argv[1]);
     return true;
}
