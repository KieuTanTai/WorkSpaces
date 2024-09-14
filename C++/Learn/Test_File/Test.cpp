#include <iostream>
#include <stdio.h>
#include <cmath>
struct data
{
	float xA, yA, xB, yB, xC, yC, xD, yD, xO, yO;
	float xAB, yAB, xAD, yAD, AC, BD, AB, CD, AD, BC;
	float length, width, S, C, NC;
}my_struct;

void HCN()
{
	std::cout << " diem xA: ";
	std::cin >> my_struct.xA;
	std::cout << " diem yA: ";
	std::cin >> my_struct.yA;
	std::cout << "Length: ";
	std::cin >> my_struct.length;
	std::cout << "width: ";
	std::cin >> my_struct.width;
	std::cout << "A(" << my_struct.xA << "," << my_struct.yA << ")" << std::endl;
	std::cout << "Length:" << my_struct.length << std::endl;
	std::cout << "Width:" << my_struct.width << std::endl;
	system("clear");
	// toa do cac diem HCN
	my_struct.yB = my_struct.yA;
	my_struct.yAB = my_struct.yB - my_struct.yA;
	my_struct.xAB = sqrt(pow(my_struct.length, 2) * 1.0 - pow(my_struct.yAB, 2) * 1.0);	// xAB = ?
	my_struct.xB = my_struct.xAB - my_struct.xA;
	my_struct.xC = my_struct.xB;
	my_struct.xD = my_struct.xA;
	my_struct.xAD = my_struct.xD - my_struct.xA;
	my_struct.yAD = sqrt(pow(my_struct.xAD, 2) * 1.0 + pow(my_struct.width, 2) * 1.0); // yAD = ?
	my_struct.yD = my_struct.yAD - my_struct.yA;
	my_struct.yC = my_struct.yD;
	// tam O
	my_struct.xO = (my_struct.xA + my_struct.xB) / 2;
	my_struct.yO = (my_struct.yA + my_struct.yB) / 2;

	std::cout << "A(" << my_struct.xA << "," << my_struct.yA << ")" << std::endl;
	std::cout << "B(" << my_struct.xB << "," << my_struct.yB << ")" << std::endl;
	std::cout << "C(" << my_struct.xC << "," << my_struct.yC << ")" << std::endl;
	std::cout << "D(" << my_struct.xD << "," << my_struct.yD << ")" << std::endl;
	std::cout << "O(" << my_struct.xO << "," << my_struct.yO << ")" << std::endl;
	for (int i = 0; i <= my_struct.length; i++)
	{
		for (int j = 0; j <= my_struct.width; j++)
		{
			if ((j == 0) || (j == my_struct.width) || (i==0) || (i==my_struct.length))
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}
		}

		std::cout << "\n";
	}

	return;
}

void S_V_NC()
{
	//area
	my_struct.S = sqrt(pow(my_struct.xAB, 2) + pow(my_struct.yAB, 2)) * sqrt(pow(my_struct.xAD, 2) + pow(my_struct.yAD, 2));
	//perimeter
	my_struct.C = (sqrt(pow(my_struct.xAB, 2) + pow(my_struct.yAB, 2)) + sqrt(pow(my_struct.xAD, 2) + pow(my_struct.yAD, 2))) * 2;
	my_struct.NC = sqrt(pow(my_struct.xAB, 2) + pow(my_struct.yAB, 2)) + sqrt(pow(my_struct.xAD, 2) + pow(my_struct.yAD, 2));
	std::cout << "the area of a rectangle: " << my_struct.S << std::endl;
	std::cout << " the perimeter of a rectangle: " << my_struct.C << std::endl;
	std::cout << " the half perimeter of a rectangle: " << my_struct.NC << std::endl;
	return;
}
void diagonal()
{
	my_struct.AC = sqrt(pow(my_struct.xA, 2) + pow(my_struct.yA, 2)) + sqrt(pow(my_struct.xC, 2) + pow(my_struct.yC, 2));
	my_struct.BD = my_struct.AC;
	std::cout << "the diagonal of a rectangle: " << my_struct.AC << std::endl;
	return;
}
int main()
{
	system("clear");
	HCN();
	S_V_NC();
	diagonal();
	return 0;
}