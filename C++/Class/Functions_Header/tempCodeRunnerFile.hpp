#include <random>
#include <cmath>
#include <climits>
#include <fstream>
//random function
double random_Number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    return std::rand() % 10000 + 1;
}

//prime number function
bool prime_Number(int temp)
{
    if(temp < 2)
        return false;
    for(int i=2; i<sqrt(temp); i++)
    {
        if(temp%2 == 0)
            return false;
    }
    return true;
}
void Search_Max( std::ostream file_out,int Row, int Column, int **array)
{
    int TEMP=INT_MIN;
     int count=0;
     //search max element and others same max element;
     for(int i=0; i<Row; i++)
     {
          for(int j=0; j<Column; j++)
          {
               if(array[i][j]>TEMP)
               {
                    TEMP=array[i][j];
                    count++;
               }
          }
     }
     file_out<<TEMP<<"  "<<count<<std::endl;
}
//heap sort function
void heapify(int *array, int Number, int i) //max heapify function
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;
    if(left < Number && array[left] > array[largest])
        largest = left;
    if(right < Number && array[right] > array[largest])
        largest = right;
    if(largest != i)
    {
        std::swap(array[i], array[largest]);
        heapify(array, Number, largest);

    }
}
void heap_Sort(int *array, int Number) //heap sort function
{
    for(int i = Number/2 -1; i>=0; i--)
        heapify(array, Number, i);
    for(int i = Number-1; i>0; i--) //swap the first and the last element and heapify the reduced heap
    {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}