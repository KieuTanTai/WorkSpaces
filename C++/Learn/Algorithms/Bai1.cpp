#include<iostream>
#include<stdbool.h>
#include<cstring>
#include<sstream>
#include<algorithm>

bool checkNumber (char *input) 
{
     for (int i = 0; i < strlen(input); i++)
          if(!isdigit(input[i]))
               return false;
     return true;
}

bool checkInput (int argc, char *input[])
 {
     if (argc <= 1)
          return false;
     else 
     {
          for (int i = 1; i < argc; i++)
               if (!checkNumber(input[i]))
                    return false;
          return true;
     }     
}

void showArray (int length, int *input)
{
     for (int i = 0; i < length; i++)
          std::cout << input[i] << "   ";
     std::cout << std::endl;
}

void bubbleSort (int length, int *input) 
{
     for (int i = 0; i < length - 1; i++) 
     {
          bool check = false;
          for (int j = 0; j < length - i - 1; j++)
               if (input[j] > input[j+1])
               {
                    std::swap(input[j], input[j+1]);
                    check = true;
               }
          if (!check)
               break;
     }
     std::cout << "bubble sort: " << std::endl;
     showArray(length, input);
}

void selectionSort (int length, int *input)
{
     for (int i = 0; i < length - 1; i++)
     {          
          int temp = input[i], index = i;
          for (int j = i+1; j < length; j++)
               if (temp > input[j])
               {
                    temp = input[j];
                    index = j;
               }
          if (temp != input[i])
               std::swap(input[index], input[i]);
     }
     std::cout << "selection sort: " << std::endl;
     showArray(length, input);
}

void insertionSort (int length, int *input) 
{
     for (int i = 1; i < length; i ++)
     {
          int tempIndex = i, nowValue = input[i];
          for (int j = i - 1; j >= 0 ; j--)
          {
               if (nowValue > input[j])
               {
                    input[j+1] = input[j];
                    tempIndex = j;
               }
          }
          input[tempIndex] = nowValue;
     }
     std::cout << "insertion sort: " << std::endl;
     showArray(length, input);
}

int partition (int *input, int start, int end) 
{
     int pivot = input[end];
     int temp = start - 1;

     for (int i = start; i < end; i++)
          if (pivot > input[i])
          {
               temp++;
               std::swap (input[temp], input[i]);
          }
     std::swap(input[++temp], input[end]);
     return temp;
}

void quickSort (int *input, int start, int end)
{
     if (end <= start)
          return;
     int pivot = partition(input, start, end);
     quickSort (input, start, pivot - 1);
     quickSort (input, pivot + 1, end);
}

int main (int argc, char *argv[])
{
     if (!checkInput(argc, argv))
     {
          std::cout << "error input!" << std::endl;
          return false;
     }
     else 
     {
          int *input = new int[argc - 1];
          int index = 0;
          for (int i = 1; i < argc; i++)
          {
               input[index] = atoi(argv[i]);
               index++;
          }
          // bubbleSort(argc - 1, input);
          // selectionSort(argc - 1, input);
          for (int i = 0; i < index; i++)
               std::cout << input[i] << "\t";
          std::cout<< index << std::endl;
          quickSort(input, 0, index - 1);
          for (int i = 0; i < index; i++)
               std::cout << input[i] << std::endl;
     }
     return true;
}