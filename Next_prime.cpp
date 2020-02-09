/*
    Next Prime Number - Have the program find prime numbers until the user chooses to stop asking for the next one.
    09/02/2020
    @ by Jiøí Klimek
*/

#include <iostream>
#include <cmath>

bool UserInput();
bool IsPrime(int num);

int main()
{
    std::cout << "This program displays prime numbers in order, first prime number is obviously 1.\n";

    unsigned int prime{ 1 };
    while (UserInput() == true) {
        ++prime;
        while (!IsPrime(prime)) {
            ++prime;
        }
        std::cout << "Next prime number is " << prime << '\n';
    }

    return 0;
}

bool UserInput() {
    while (true) {
        std::cout << "Do you want to see next prime number? (y/n)\n";
        std::string input;
        std::cin >> input;
        if (input == "y") return true;
        if (input == "n") return false;
        std::cout << "Invalid input, please try again or exit program.";
    }
}

bool IsPrime(int num) {
    int temp{ static_cast<int>(sqrt(num)) };
    for (int i{ 2 }; i <= temp; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}