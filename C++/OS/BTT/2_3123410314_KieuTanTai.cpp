#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pthread.h>
#include<cstring>
#include<stdbool.h>
#include<random>
#include<fstream>
#include<sstream>
#include<algorithm>

struct container {
     int count = 0;
     int t_index = 0, b_index = 0;
     int *halfTop = new int[count];
     int *halfBottom = new int[count];
     std::string inputFile;
     std::string outputFile;
};

bool checkExistFile (char *file) 
{
     if (!std::ifstream (file))
          return false;
     return true;
}

bool checkInput (int argc, char *input) 
{
     if (argc !=3)
          return false;

     if(!checkExistFile(input))
          return false;
     return true;     
}

bool checkNumber (std::string input) {
     for (int i = 0; i < input.length(); i++)
          if (!isdigit(input[i]))
               return false;
     return true;
}

void *thread1 (void * arg)
{
     container *ct = &(*(container*)arg);
     for (int i = 0; i < ct->t_index - 1; i++) 
     {
          int temp = i;
          for (int j = i; j < ct->t_index; j++)
               if (ct->halfTop[i] > ct->halfTop[j])
                    temp = j;
          if (temp != i)
               std::swap(ct->halfTop[i], ct->halfTop[temp]);
     }
     std::cout << "hello" << std::endl;
     pthread_exit(NULL);
}

void *thread2 (void * arg)
{
     container *ct = &(*(container*)arg);
     for (int i = 0; i < ct->b_index - 1; i++) 
     {
          int temp = i;
          for (int j = i; j < ct->b_index; j++) 
               if (ct->halfBottom[i] > ct->halfBottom[j])
                    temp = j;
               if (temp != i)
                    std::swap(ct->halfBottom[i], ct->halfBottom[temp]);
     }
     std::cout << "hello" << std::endl;
     pthread_exit(NULL);
}

void *thread3 (void * arg)
{
     int b_index = 0;
     container *ct = &(*(container*)arg);
     std::ofstream file;
     file.open(ct->outputFile);
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }
     file << "sort numbers: \n";
     for (int i = 0; i < ct->count; i++) 
     {
          if (i != 0 && i % 20 == 0)
               file << "\n";
          if (i <= ct->t_index)
               file << ct->halfTop[i] << "   ";
          else 
          {
               file << ct->halfBottom[b_index] << "   ";
               b_index++;
          }
     }
     file.close();
     pthread_exit(NULL);
}

int main (int argc, char *argv[]) 
{
     if (!checkInput(argc, argv[1]))
     {
          std::cout << "error input!" << std::endl;
          exit(1);
     }
     container ct;
     int temp, i = 0;
     ct.inputFile = argv[1];
     ct.outputFile = argv[2];
     pthread_t tid1, tid2, tid3;

     std::ifstream file(argv[1]);
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }

     while (file >> temp)
          ct.count ++;
     file.close();

     int topIndex = ct.count / 2 ;
     int bottomIndex = ct.count / 2 + 1;
     ct.halfTop = new int[topIndex - 1];
     ct.halfBottom = new int[bottomIndex - 1];

     std::ifstream pFile(argv[1]);
     while (pFile >> temp) 
     {
          if (i <= topIndex) 
          {
               ct.halfTop[ct.t_index] = temp;
               ct.t_index++;
          }
          else 
          {
               ct.halfBottom[ct.b_index] = temp;
               ct.b_index++;
          }
          i++;
     }

     pthread_create(&tid1, NULL, thread1, &ct);
     pthread_create(&tid2, NULL, thread2, &ct);
     pthread_join(tid1, NULL);
     pthread_join(tid2, NULL);
     pthread_create(&tid3, NULL, thread3, &ct);
     pthread_join(tid3, NULL);

     pFile.close();
     return true;
}