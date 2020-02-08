/*

		@Created by Jiøí Klimek
				08/02/2020

		Find PI to the Nth Digit
		Enter a number and have the program generate PI up to that many decimal places.
		Keep a limit to how far the program will go.

*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>

int GetDecimalPlaces();
void PrintPi(int dec_places);


int main()
{
	PrintPi(GetDecimalPlaces());
	return 0;
}

int GetDecimalPlaces()
{
	while (true) {
		std::cout << "Enter integer number for how many decimal places of Pi you would like to see.(limit 1-30)\n";
		int decimal_spaces{};
		std::cin >> decimal_spaces;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, please try again\n";
			continue;
		}
		if (decimal_spaces > 30 || decimal_spaces < 1) {
			std::cout << "You entered number larger than 30 or smaller than 1, please try again.\n";
			continue;
		}
		return decimal_spaces;
	}
}

void PrintPi(int dec_places)
{
	double pi{ 3.141592653589793238462643383279 };
	std::cout << std::setprecision(dec_places + 1) << pi << '\n';
}