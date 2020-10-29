#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    std::vector<std::tuple<int, char>> code;
    int amt;
    cin >> amt;

    for (unsigned int i = 0; i < amt; i++) {
        int numb;
        char symbol;

        cin >> numb >> symbol;
        cin.clear();

        code.push_back(std::tuple<int, char>(numb, symbol));
    }

    for (const std::tuple<int, char>& values : code) {
        for (unsigned int i = 0; i < std::get<0>(values); i++) {
            cout << std::get<1>(values);
        }
        cout << std::get<1>(values) << endl;
    }
    return 0;
}
