#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pthread.h>
#include<cstring>
#include<stdbool.h>
#include<random>
#include<fstream>
#include<sstream>

struct container {
     float average;
     int count = 0;
     int *ascNumbers = new int[count];
     std::string primeNumbers;
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

bool isPrime(int num) {
    if (num < 2)
        return false;

    if (num % 2 == 0)
        return false;
    
    // Check divisibility from 3 to sqrt(num)
    for (int i = 2; i <= std::sqrt(num); i += 2)
        if (num % i == 0)
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
     std::ifstream file;
     file.open(ct->inputFile);
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }
     int sum = 0, count = 0, temp;
     while (file >> temp) {
          sum += temp;
          count++;
     }
     if (count != 0)
          ct->average = sum * 1.0 / count;
          ct->count = count;
     file.close();
     pthread_exit(NULL);
}

void *thread2 (void * arg)
{
     container *ct = &(*(container*)arg);
     std::ifstream file;
     file.open(ct->inputFile);
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }

     int *numsArray = new int[ct->count - 1];
     int temp, i = 0;;
     while (file >> temp) 
     {
          numsArray[i] = temp;
          i++;
     }

     for (int i = 0; i < ct->count - 1; i++) {
          int temp = i;
          for (int j = i; j < ct->count; j++) 
               if (numsArray[i] > numsArray[j])
                    temp = j;
               if (temp != i)
                    std::swap(numsArray[i], numsArray[temp]);
     }

     ct->ascNumbers = new int[ct->count - 1];
     ct->ascNumbers = numsArray;
     file.close();
     pthread_exit(NULL);
}

void *thread3 (void * arg)
{
     container *ct = &(*(container*)arg);
     std::ifstream file(ct->inputFile);
     int temp;
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }

     int br = 0;
     while (file >> temp) {
          if (br != 0 && br % 10 == 0)
               ct->primeNumbers.append("\n");
          if (isPrime(temp))
               ct->primeNumbers.append(std::to_string(temp) + "  ");
          br++;
          
     }
     file.close();
     pthread_exit(NULL);
}

void *thread4 (void * arg)
{
     container *ct = &(*(container*)arg);
     std::ofstream file;
     file.open(ct->outputFile);
     if (!file.is_open()) 
     {
          std::cout << "error !" << std::endl;
          perror("Error: ");
          exit(1);
     }

     file << "average: \n";
     file << ct->average << "\n";

     file << "sort numbers: \n";
     for (int i = 0; i < ct->count; i++) {
          if (i != 0 && i % 10 == 0)
               file << "\n";
          file << ct->ascNumbers[i] << "    ";
     }
     file << "\n";
     file << "prime numbers: \n";
     file << ct->primeNumbers << "\n";
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
     ct.inputFile = argv[1];
     ct.outputFile = argv[2];
     pthread_t tid1, tid2, tid3, tid4;
     pthread_create(&tid1, NULL, thread1, &ct);
     pthread_join(tid1, NULL);
     pthread_create(&tid2, NULL, thread2, &ct);
     pthread_join(tid2, NULL);
     pthread_create(&tid3, NULL, thread3, &ct);
     pthread_join(tid3, NULL);
     pthread_create(&tid4, NULL, thread4, &ct);
     pthread_join(tid4, NULL);

     std::cout << ct.count << std::endl;
     std::cout << ct.average << std::endl;
     std::cout << *ct.ascNumbers <<std::endl;
     // std::cout << ct.primeNumbers << std::endl;
     return true;
}