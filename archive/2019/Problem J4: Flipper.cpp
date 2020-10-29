#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int count(std::vector<char> arr, char target) {
    int total = 0;
    for (const char& i : arr) {
        if (i == target) {
            total++;
        }
    }
    return total;
}

int main() {
    string input;
    getline(cin, input);
    std::vector<char> rule;

    for (const char& i : input) {
        rule.push_back(i);
    }

    std::vector<int> grid = {1, 2, 3, 4};

    if (count(rule, 'H') % 2 == 1) {
        grid = {3, 4, 1, 2};
    }
    if (count(rule, 'V') % 2 == 1) {
        grid = {grid[1], grid[0], grid[3], grid[2]};
    }

    cout << grid[0] << grid[1] << endl << grid[2] << grid[3] << endl;
}
