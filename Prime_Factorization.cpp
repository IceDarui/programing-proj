/*
    Have the user enter a numberand find all Prime Factors(if there are any) and display them.
    09/02/2020
    @by Jiøí Klimek 
*/


#include <vector>
#include <iostream>

using u_int = unsigned int;

std::vector<int> Factors(int num);
bool IsPrime(int num);
std::vector<int> PrimeFactors(int num);
void PrintFactors(const std::vector<int> &ref);


int main()
{
    std::cout << "Enter integer you want to see prime factors for.\n";
    int var{};
    std::cin >> var;
    PrintFactors(PrimeFactors(var));
    return 0;
}


std::vector<int> Factors(int num) {
    std::vector<int> ret;
    for (int i{ 1 }; i <= num; ++i) {
        if (num % i == 0)
            ret.push_back(i);
    }
    return ret;
}

bool IsPrime(int num) {
    int temp{ num / 2 };
    for (int i{ 2 }; i <= temp; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

std::vector<int> PrimeFactors(int num) {
    std::vector<int> ret;
    std::vector<int> factors = { Factors(num) };
    for (int i{0}; i < std::size(factors); ++i) {
        if (IsPrime(factors[i]) == true)
            ret.push_back(factors[i]);
    }
    return ret;
}

void PrintFactors(const std::vector<int> &ref) {
    if (ref.size() == 0)
        std::cout << "There are no prime factors for this number";
    for (const auto &i :ref)
        std::cout << i << '\n';
}