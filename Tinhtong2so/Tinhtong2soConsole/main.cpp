#include <iostream>
#include <conio.h>
#include "Giaitoan.h"

int main(int argv, char* argc[]) {
	Giaitoan objGiaitoan;

	int tong = objGiaitoan.tinhtonghaiso(3, 4);

	std::cout << "Tong = " << tong << std::endl;

	getch();
	return 0;
}