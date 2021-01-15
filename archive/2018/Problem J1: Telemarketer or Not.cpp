#include <iostream>

std::string input() {
    std::string val;
    std::cin >> val;
    return val;
}

int main() {
    int nums[] = {std::stoi(input()), std::stoi(input()), std::stoi(input()), std::stoi(input())};
    if ((nums[0] == 8 || nums[0] == 9) && (nums[1] == nums[2]) && (nums[3] == 8 || nums[3] == 9)) {
        std::cout << "ignore" << std::endl;
    } else {
        std::cout << "answer" << std::endl;
    }
}
