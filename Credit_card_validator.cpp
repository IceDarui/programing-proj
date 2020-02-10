/*
        Credit Card Validator - Takes in a credit card number from a common credit card vendor (Visa, MasterCard, American Express, Discover)
        and validates it to make sure that it is a valid number.
        09/02/2020
        @ by Jiøí Klimek
*/


//I will have to search more into Luhn algorithm, it apears that new cards no longer works,
//but it is high posibility to be fault on my part thought.

//Update 10/02/2020 found the problem, bad understading of algorithm in final process
        //Problem was me checking sum modulo to check digit instead of adding it.

#include <iostream>
#include <vector>
#include <algorithm>

std::string GetUserInput();
bool Validate(std::string& string);

int main()
{
    std::string card_id{ GetUserInput() };
    if (Validate(card_id))
        std::cout << "Your card is valid.";
    else
        std::cout << "Invalid card ID.";
    return 0;
}

std::string GetUserInput() {
    std::cout << "Enter number of credit card to validate: ";
    std::string card_id;
    std::cin >> card_id;
    return card_id;
}

bool Validate(std::string& string) {
    int sum{};
    std::vector<int> vec;
    for (auto& i : string) {
        vec.push_back(i - '0');
    }

    int check_digit{ vec.back() };
    vec.pop_back();
    auto end = vec.end();
    std::reverse(vec.begin(), end);
    auto it = vec.begin();
    int iter_check{2};
    
    while (it != vec.end()) {
        if (iter_check % 2 == 0) {
            *it *= 2;
        }
        if (*it > 9)
            *it -= 9;
        ++it;
        ++iter_check;
    }
    for (auto& i : vec) {
        sum += i;
    }
    if ((sum+check_digit) % 10 == 0) 
        return true;
    return false;
}