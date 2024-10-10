#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<cstring>

bool checkInput(char *input) {
     for (int i=0; i < strlen(input); i++) {
          if(!isdigit(input[i]))
               return false;
     }
     return true;
}

int sum (int argc, char *input[]) {
     double sum = 0;
     for( int i=0; i < argc; i++) {
          if (checkInput(input[i]))
               sum += atoi(input[i]);
     }
     return sum;
}

int main(int argc, char *argv[]) {
     if(argc == 1) {
          std::cout << "none input" << std::endl;
          return false;
     }
     std::cout << "sum = " << sum(argc ,argv) << std::endl;
     return true;
}
