#include <iostream>
#include <stdio.h>
#include <math.h>
struct bienN
{
    int N;
}bien;
int slmin(int J,int  K)
{
    bien.N = J;
    if(bien.N%2==0)
    {
        K = bien.N+1;
        std::cout<<"so le nho nhat lon hon N: " << K <<std::endl;
        bien.N = K;
    }
    else
    {
        K = bien.N +2;
        std::cout << "so le nho nhat lon hon N: " << K <<std::endl;
        bien.N =K;
    }
    return 0;
}
int Nsnt(int n, int dem)
{
    std::cout << bien.N <<std::endl;
    
    std::cout <<"dem " << dem <<std::endl;
    std::cout << "so nguyen to thu N: " << n <<std::endl;
    return dem;
}
int main()
{
    int X, Y=0;
    int Z=3, R=0;
    std::cout << " X = ";
    std::cin >>X;
    slmin(X, Y);
    Nsnt(Z, R);
}