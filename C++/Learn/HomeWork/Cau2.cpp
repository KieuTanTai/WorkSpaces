#include <iostream>
#include <cstdlib>
#include <math.h>
//check max
void MAX(int m, int n, float &max, float mang[100][100])
{
    for (int i =0; i < m; i++)
    {
        for(int j=0; j<n; j++)
        {
              if(mang[i][j] >max)
                max=mang[i][j];
        }
    }
}
//nhap bang
float chiPhi_pc(int &m, int &n, float mang[100][100])
{
    for(int i=0; i <m; i++)
    {
        for( int j= 0; j < n; j++)
        {
            std::cout << "mang [" << i*n +j << "]= ";
            std::cin >> mang[i][j];
        }
    }
    system("clear");
    std::cout<<"bang chi phi phan cong: " <<std::endl;
    for(int i=0; i <m; i++)
    {
        for(int j=0; j <n; j++)
        {
            std::cout<<mang[i][j] << "\t";
        }
        std::cout << std::endl;        
    }
    return 0;
}
// phan tu nho nhat
float chiPhi_min(int m, int n, float mang[100][100])
{
    float max=0, min=0;
    MAX(m, n, max, mang);
    for(int i=0; i < m; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(mang[i][j] < max)
                {
                    min = mang[i][j];
                    max = min;
                }
            }
        }
    std::cout<< " chi phi thap nhat: " << min << std::endl;
    std::cout<<" cac cach phan cong: " <<std::endl;
    for(int i=0; i < m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mang[i][j] <= min)
            {
                std::cout<<"("<<i<<","<<j<<") "<<"\t";
            }
        }
    }
    std::cout << std::endl;
    return min;
}
//gia tri trung binh cv
float cptb_cv(int m, int n, float mang[100][100])
{
    float chiPhi_tb, chiPhi_v=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            chiPhi_v+=mang[i][j];
        }
        chiPhi_tb = chiPhi_v /n;
        std::cout<<"chi phi trung binh viec " << i << " la: " <<chiPhi_tb <<std::endl;
    }
    return chiPhi_tb;
}
//gia tri trung binh nv
float cptb_nv(int m, int n, float mang[100][100])
{
    float chiPhi_tbnv, chiPhi_nv=0;
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<m; i++)
        {
            chiPhi_nv+=mang[i][j];
        }
        chiPhi_tbnv = chiPhi_nv /m;
        std::cout<<"chi phi trung binh nhan vien " << j << " la: " <<chiPhi_tbnv <<std::endl;
    }
    return chiPhi_tbnv;
}
int main(int argc, char* argv[])
{
    int so_cv=0, so_nv=0;
    float mang[100][100];
    while(so_cv <=0 || so_nv <=0)
    {
        std::cout<<"so luong cong viec: ";
        std::cin >>so_cv;
        std::cout<<"so luong nhan vien: ";
        std::cin>>so_nv;
    }
    system("clear");
    std::cout<< "so cong viec = " << so_cv <<std::endl;
    std::cout<<"so nhan vien = " << so_nv << std::endl;
    chiPhi_pc(so_cv, so_nv, mang);
    chiPhi_min(so_cv, so_nv, mang);
    cptb_nv(so_cv, so_nv, mang);
    cptb_cv(so_cv, so_nv, mang);
    return 0;
}