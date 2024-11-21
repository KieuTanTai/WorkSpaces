#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pthread.h>
#include<cstring>
#include<stdbool.h>
#include<random>
#include<fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

// validate
bool checkExist (char *input) 
{
     std::ifstream file;
     file.open(input);
     if (!file.is_open())
     {
          exit(2);
     }
     else 
          file.close();
     exit(0);
}

// process
void processTest (int number)
 {
     // share memory
     long SIZE = number * 100;
     char  * shm;
     int shmID;
     key_t key = ftok(".", 't');
     shmID = shmget(key, SIZE, IPC_CREAT | 0666);
     shm = (char*)shmat(shmID, 0, 0);

     pid_t pid = fork();
     if (pid > 0) 
     {
          // get input -> child
          memcpy(shm, &number, SIZE);

          // wait child process
          wait(NULL);

          //print pi
          std::cout << "pi: " << shm << std::endl;
     }
     if (pid == 0) 
     {
          createThreads(0);
          // wait threads

          // get pi and write to share memory 
     }
}

// function on child process 
void createThreads(int number) {
 pthread_t tid1, tid2, tid3;
     pthread_create(&tid1, NULL, thread1, &number);
     pthread_create(&tid2, NULL, thread2, &number);
     pthread_join(tid1, NULL);
     pthread_join(tid2, NULL);
     pthread_create(&tid3, NULL, thread3, NULL);
} 

// threads
// create random
void *thread1 (void * arg)
{
     pthread_exit(NULL);
}

// create random negative
void *thread2 (void * arg) 
{
     pthread_exit(NULL);
}

// write file data when t1 & t2 done
void *thread3 (void * arg) 
{
     pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
     processTest(atoi(argv[1]));
     return 0;
}