#include<iostream>
#include<cstring>
#include<sstream>

double SumRange(double input) {
     double sum = 0;
     for(int i = 1; i <= input; i++) 
          sum+= i;
     return sum;
}

int SumNumInput(double input) {
     double temp, sum = 0;
     while(input > 0) {
          temp = static_cast<double>(input)/(double)10;
          input /= 10;
          sum+=temp;
     }
     return sum;
}

int SumNumInString(std::string input) {
     int sum = 0;
     std::stringstream ss(input);
     std::string temp;
     while(ss >> temp) {
          try {
               sum += stoi(temp);
          } catch (std::exception &e) {
               std::cerr<<e.what() << std::endl;
          }
     }
     return sum;
}

int main(int agrc, char **agrv) {
     bool err;
     double input;
     do
     {
          std::cin.clear();
          std::cin.ignore(256, '\n');
          system("clear");
          if(!err)
               std::cout << "input = ";
          else {
               std::cout << "error input please try again! \n" << "input = ";
          }
          std::cin >> input;
          if(std::cin.fail())
               err = true;
          else 
               err = false;
     } while (err);
     std::string stringInput;
     std::cout << "string input: ";
     std::cin.ignore();
     std::getline(std::cin, stringInput);
     std::cout << "sum = " << SumRange(input)<< std::endl;
     std::cout << "sum name number = " << SumNumInput(input) << std::endl;
     std::cout << "count number in string: " << SumNumInString(stringInput) << std::endl;
     return 0;
}