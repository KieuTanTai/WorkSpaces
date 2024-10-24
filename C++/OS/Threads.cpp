#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pthread.h>
#include<cstring>
#include<stdbool.h>
#include<random>
#include<fstream>

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

void *thread1 (void * arg)
{

     std::ofstream file;
     file.open("../TestDocs/data.txt");
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }
     int input = *(int *)arg;
     std::srand(time(NULL));
     for (int i = 0; i < input; i++)
     {
          file << (rand() % 1000 + 1) << std::endl;
     }
     file.flush();
     file.close();
     pthread_exit(NULL);
}

void *thread2 (void * arg) 
{
     int count = 0;
     std::ifstream file;
     file.open("../TestDocs/data.txt");
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          exit(1);
     }
     std::string temp;
     while (std::getline(file, temp)) 
     {
          int number = std::stoi(temp);
          if (number % 3 == 0)
               count ++;
     }
     file.close();
     std::cout << "count = " << count << std::endl;
     pthread_exit(NULL);
}

int main (int argc, char * argv[]) 
{
     if (!checkInput(argc, argv[1]))
     {
          std::cout << "error input!" << std::endl;
          exit(1);
     }
     int temp = atoi(argv[1]);
     pthread_t tid1, tid2;
     pthread_create(&tid1, NULL, thread1, &temp);
     pthread_join(tid1, NULL);
     pthread_create(&tid2, NULL, thread2, NULL);
     pthread_join(tid2, NULL);
     return true;
}