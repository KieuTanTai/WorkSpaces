#include <iostream>
#include <climits>
#include <math.h>
bool SNT(int x)
{
    if(x<2)
        return false;
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int **input_array(int &m, int &n)
{  
    int **array = new int*[m];
    for(int i=0; i<m;i++)
    {
        array[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            std::cout <<"array["<<i<<"]["<<j<<"]= ";
            std::cin >> array[i][j];
        }
    }
    return array;
}
int output_array(int **array, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n;j++)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return **array;
}
int count_prime(int **array, int m, int n)
{
    int point =0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(SNT(array[i][j]))
            point+=1;
        }
    }
    std::cout <<"mang a chua " <<point<<" so nguyen to"<<std::endl;
    return point;
}
int sum_column(int **array, int m, int n)
{
    int sum;
    for(int i=0; i<m; i++)
    {
        sum=0;
        for(int j=0; j<n; j++)
        {
            sum+=array[i][j];
        }
        std::cout<<"sum"<<i<<"= "<<sum<<std::endl;
    }
    return sum;
}
int max_min_array(int **array, int m, int n)
{
    int min=INT_MAX;
    int max= INT_MIN;
    for(int i=0; i<m;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(array[i][j]>max)
            max=array[i][j];
        }
        if(min>max)
        min=max;
    }
    std::cout << "gia tri nho nhat trong cac gia tri lon nhat la: " <<min<<std::endl;
    return min;
}
int main()
{
    int m, n;
    while(m<0 || n<0)
    {
    std::cout <<"so dong m= ";
    std::cin >>m;
    std::cout <<"so cot n= ";
    std::cin >>n;
    system("clear");
    }  
    int **array=input_array(m, n);
    output_array(array, m, n);
    count_prime(array, m, n);
    sum_column(array, m, n);
    max_min_array(array, m, n);
    delete []array;
    return 0;
}