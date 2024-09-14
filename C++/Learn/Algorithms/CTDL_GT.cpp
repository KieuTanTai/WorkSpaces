#include <iostream>
#include <vector>
#include <random>

void heapify(int arr[], int n, int i /*index*/)
{
     int largest = i; //initialize the largest as root
     int left = i*2 +1; 
     int right = i*2 +2;
     if(left < n && arr[left] > arr[largest])
          largest = left;   
     if(right < n && arr[right] > arr[largest])
          largest = right;
     if(largest != i)
     {
          std::swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
     }
}

void heapSort(int arr[], int n)
{
     for(int i = n/2 -1 ; i>=0; i--) //build max heap
          heapify(arr, n, i);
     for(int i=n-1; i>0; i--) // swap the first and the last element and heapify the reduced heap
     {
          std::swap(arr[0], arr[i]);
          heapify(arr, i, 0); 
     }
}

int main()
{
     int arr[] = {11, 15, 1454, 5, 5, 119, 8};
     int n = sizeof(arr)/sizeof(arr[0]);
     heapSort(arr, n);
     for(int i = 0; i<n; i++) //print array
          std::cout<<arr[i]<<" ";
     std::cout<<std::endl;
     return 0;
}