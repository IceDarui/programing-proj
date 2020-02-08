/*
        Fibonacci number sequence
        @ Jiøí Klimek
*/

#include <iostream>

int UserNumber();
void DisplayResult(int count);

int main()
{
    DisplayResult(UserNumber());
    return 0;
}


int UserNumber() {
    std::cout << "Enter how many fibonacci number would you like to see\n";
    int temp{};
    std::cin >> temp;
    return temp;
}

void DisplayResult(int count) {
    int f_min{};
    int f_max{1};

    std::cout << "Fibonacci numbers:\n";

    if (count >= 1) std::cout << 1 << '\n';

    if (count > 1) {
        for (int i{}; i < count -1 ; ++i) {
            int temp{ f_max + f_min };
            f_min = f_max;
            f_max = temp;
            std::cout << temp << '\n';
        }
    }
}