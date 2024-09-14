#include <iostream>
#include <stdio.h>
#include <climits>
#include <cstdlib>
#include <cmath>
//check snt
bool prime_number(int number)
{
    if(number<2)
    {
        return 0;
    }
    else
    {
        for(int i=2; i<= sqrt(number); i++)
        {
            if(number%i==0)
                return 0;
        }
    }
    return 1;
}
//check max min
void max_min( int row, int column, int &max, int &min, int **arrayA)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(i%2==0)
            {
                if(min > arrayA[i][j])
                    min = arrayA[i][j];
            }
            else 
            {
                if(max < arrayA[i][j])
                    max = arrayA[i][j];
            }
        }
    }
}
// khoi tao mang A
int **Array_A(int row, int column)
{
    int **arrayA = new int*[row];
    for(int i=0; i<row; i++)
    {
        arrayA[i] = new int[column];
        for(int j=0; j<column; j++)
        {
            std::cout<<" enter element of arrayA["<<i<<"]["<<j<<"]= ";
            std::cin>>arrayA[i][j];
        }
    }
    return arrayA;
}
// xuat mang A
void show_Array_A(int row, int column, int **arrayA)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            std::cout << arrayA[i][j]<< " ";
        std::cout<<std::endl;
    }
}
// khoi tao mang B
int **Array_B(int row, int column, int **arrayA)
{
    int min = INT_MAX;
    int max = INT_MIN;
    max_min(row, column, max, min, arrayA);
    std::cout<<"min = " << min << std::endl;
    std::cout<<"max = " << max << std::endl;
    int **arrayB= new int *[row];
    for(int i=0; i<row; i++)
    {
        arrayB[i] = new int[column];
        for(int j=0; j<column; j++)
        {
            if(i%2!=0)
                arrayB[i][j]=arrayA[i][j]*min;
            else 
                arrayB[i][j]=arrayA[i][j]*max;
        }
    } 
    return arrayB;
}
// xuat mang B
void show_Array_B(int row, int column, int **arrayB)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            std::cout<<arrayB[i][j]<<" ";
        std::cout<<std::endl;
    }
}
//dem snt dong
int count_row(int row, int column, int mark1, int **arrayA)
{
    int dem = 0;
    for(int j=0; j<column; j++)
    {
        if(prime_number(arrayA[mark1][j]))
            dem++;
    }
    return dem;
}
// dem snt cot
int count_column(int row, int column, int mark2, int **arrayA)
{
    int dem = 0;
    for(int i=0; i<row; i++)
    {
        if(prime_number(arrayA[i][mark2]))
            dem++;
    }
    return dem;
}
//khoi tao mang C
int **Array_C(int row, int column, int **arrayA)
{
    int **arrayC = new int*[row];
    for(int i=0; i<row; i++)
    {
        arrayC[i]=new int[column];
        for(int j=0; j<column; j++)
        {
            if(prime_number(arrayA[i][j]))
                arrayC[i][j]=count_row(row, column, i, arrayA) + count_column(row, column, j, arrayA) - 1;
            else
                arrayC[i][j]=count_row(row, column, i, arrayA) + count_column(row, column, j, arrayA);
        }
    }
    return arrayC;
}
//xuat mang C
void show_Array_C(int row, int column, int **arrayC)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column;j++)
            std::cout<<arrayC[i][j]<<" ";
        std::cout<<std::endl;
    }
}
int main(int argc, char *argv[])
{
    system("cls");
    int row = 0, column = 0;
    while((row <=0) || (column <= 0))
    {
        std::cout<<"row = ";
        std::cin>>row;
        std::cout<<"column = ";
        std::cin>>column;
    }
    int **array_A = Array_A(row, column);
    int **array_B = Array_B(row, column, array_A);
    int **array_C = Array_C(row, column, array_A);
    std::cout <<"array A: " <<std::endl;
    show_Array_A(row, column,array_A);
    std::cout <<"array B: " <<std::endl;
    show_Array_B(row, column, array_B);
    std::cout <<"array C: " <<std::endl;
    show_Array_C(row, column, array_C);
    delete []array_A;
    delete []array_B;
    delete []array_C;
    return 0;
}