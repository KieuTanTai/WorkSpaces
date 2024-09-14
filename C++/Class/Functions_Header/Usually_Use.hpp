#include <random>
#include <cmath>
#include <climits>
#include <fstream>
#include <algorithm>
//random function
double random_Number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    return std::rand() % 1000 +1;
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
void Search_Max( std::ostream &file_out,int Row, int Column, int **array)
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
void array_2x2(std::ostream &file_out, int Row, int Column, int **array)
{
    int *Temp = new int[Row];
    int min = INT_MIN;
    for(int i=0; i<Row-1; i++)
    {
        int Sum=0;
        for(int j=0; j<Column-1; j++)
        {
            if(prime_Number(array[i][j]) && prime_Number(array[i+1][j]) && prime_Number(array[i][j+1]) && prime_Number(array[i+1][j+1]))
                Sum+= array[i][j]+array[i+1][j]+array[i][j+1]+array[i+1][j+1];
        }
        Temp[i]=Sum;
    }
    for(int i=0; i<Row; i++)
    {
        if(Temp[i]>min)
            min=Temp[i];
    }
    file_out<<min<<std::endl;
    delete []Temp;
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
//selection sort
void selection_sort(int *array, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int tmp=array[i], k=i;
        for(int j=i+1; j<n; j++)
        {
            if(array[j] < array[i])
                k=j;
            if(k!=i)
                std::swap(array[i], array[j]);
        }
    }
}
//insertion sort
void insertion_sort(int *array, int n)
{
    for(int i=1; i<n;i++)
    {
        int x=array[i], pos=i-1;
        while(pos>=0 && x<array[pos])
        {
            array[pos+1]=array[pos];
            pos--;
        }
        array[pos+1]=x;
    }
}
//bubble sort
void bubble_sort(int *array, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int x=array[i];
        for(int j=n-1; j>i; j--)
        {
            if(array[j-1]>array[j])
                std::swap(array[j], array[j-1]);
        }
    }
}
//merge sort
void Merge(int *array, int left, int middle, int right)
{
    int i, j, k = left;
    int N1= middle - left + 1;
    int N2= right - middle;
    int *LeftArray = new int[N1];
    int *RightArray = new int[N2];
    for(i=0; i<N1; i++)
        LeftArray[i]=array[left+i];
    for(j=0; j<N2; j++)
        RightArray[j]=array[middle + j + 1];
    i=0, j=0;
    while(i<N1 && j<N2)
    {
        if(LeftArray[i]<=RightArray[j])
        {
            array[k]=LeftArray[i];
            k++, i++;
        }
        else
        {
            array[k]=RightArray[j];
            k++, j++;
        }
    }
    while(i<N1)
    {
        array[k]=LeftArray[i];
        k++, i++;
    }
    while(j<N2)
    {
        array[k]=RightArray[j];
        k++, j++;
    }
    delete [] LeftArray;
    delete [] RightArray;
}
void MergeSort(int *array, int left, int right)
{
    if(left<right)
    {
        int middle=(left+right)/2;
        MergeSort(array, left, middle);
        MergeSort(array, middle +1, right);
        Merge(array, left, middle, right);
    }
}
//quick sort 
void QuickSort(int *array, int left , int right)
{
    if(left>=right)
        return; //khong co phan tu nao hoac co 1 phan tu
    if(left +1 == right)
        if(array[left] > array[right])
            std::swap(array[left], array[right]);   //co 2 phan tu va neu phan tu dau lon hon thi swap
    else    //co hon 3 phan tu
    {
        int pivot = array[right];
        int L= left -1;
        for(int j=left; j<right; j++)
        {
            if(array[j] < pivot)
            {
                L++;
                std::swap(array[j], array[L]);
            }
        }
            std::swap(array[L+1], array[right]);
            QuickSort(array, left, L);
            QuickSort(array, L+2, right);
    }
}
//heap sort
void Heapify(int *array, int N, int i)
{
    int largest = i;
    int leftN = 2*i +1; //node trai
    int rightN = 2*i +2; //node phai
    //so sanh node trai/phai voi node hien tai
    if(leftN < N && array[largest]< array[leftN])
        largest = leftN;
    if(rightN < N && array[largest] < array[rightN])
        largest = rightN;
    if(largest != i)
    {
        std::swap(array[i], array[largest]);
        Heapify(array, N, largest);
    }
}
void HeapSort(int *array, int N)
{
    for(int i=N/2-1; i>=0; i--)
        Heapify(array, N, i); // build max heap
    for(int j= N-1; j>0; j--)
    {
        std::swap(array[0], array[j]);
        Heapify(array, j, 0);
    }
}