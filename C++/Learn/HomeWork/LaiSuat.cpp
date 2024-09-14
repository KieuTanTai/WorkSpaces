#include <iostream>
#include <math.h>
#include <cstdlib>
//ham tinh toan lai suat 
int laiSuat (int vay, int thang_vay, float lai_suat_nam)
{
    int tong_lai = 0;
    int tong, tien_lai, tien_goc;
    float lai_suat_thang;
    tien_goc = vay /thang_vay;
    lai_suat_thang = lai_suat_nam/12;
    for(int i=1 ; i <= thang_vay; i++)
    {
        std::cout<<"lai suat thang " << i << "= ";
        tien_lai = (vay - (i-1)*tien_goc) *lai_suat_thang;
        tong_lai +=tien_lai;
        std::cout << tien_lai << std::endl;
    }
    tong = vay + tong_lai;
    std::cout << "tong so tien khach phai tra = " << tong << std::endl;
    return tong;
}
int main(int argc, char *argv[])
{
    int vay, thang_vay;
    int m;
    float lai_suat;
    std::cout << "so tien khach hang vay = ";
    std::cin >> vay;
    std::cout << "so thang khach vay = ";
    std::cin >> thang_vay;
    //lai suat %
    std::cout << "phan tram lai suat nam = ";
    std::cin >> lai_suat;
    laiSuat(vay, thang_vay, lai_suat);
    return 0;
}