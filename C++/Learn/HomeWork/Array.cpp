#include <iostream>
#include <stdio.h>
#include <math.h>
int main()
{
    int dem = 0, A[50];
    int n, x, k, z;
    std::cout <<"n= ";
    std::cin>>n;
    std::cout <<"k= ";
    std::cin>>k;
    std::cout <<"z= ";
    std::cin>>z;
    for(int i=0; i < n; i++)
    {  
            A[i] = k+1;
            k++;
            std::cout << A[i] << "\t";
    }
    for(int i=0; i < n; i++)
    {  
        A[i];
        if(A[i]==z)
        {
            std::cout<<"z: " << A[i] <<std::endl;
            break;
        }
    }
    x = sizeof(A)/sizeof(int);
    std::cout <<"phan tu = " <<x<<std::endl;
}
