#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define map std::unordered_map

/** Gets the letters of string and puts their occurences in a dictionary */
map<char, int> getLetters(string str) {
    map<char, int> letters;

    for (char& letter : str) {
        letters[letter]++;
    }

    return letters;
}

int main() {
    string str1;
    string str2;

    cin >> str1;
    cin >> str2;

    auto str1Letters = getLetters(str1);
    auto str2Letters = getLetters(str2);
    bool didFinish = false;

    for (auto const& entry : str1Letters) {
        char letter = entry.first;
        int str1Count = entry.second;
        int str2Count = str2Letters[letter];
        int letterCountDifference = str1Count - str2Count;

        if (letterCountDifference == 0) {
            str2Letters[letter] = 0;
        } else if (letterCountDifference <= -1) {
            cout << "N" << endl;
            didFinish = true;

            break;
        } else {
            int wildCardCount = str2Letters['*'];

            if (wildCardCount >= letterCountDifference) {
                str2Letters['*'] = wildCardCount - letterCountDifference;
                str2Letters[letter] = 0;
            } else {
                cout << "N" << endl;
                didFinish = true;

                break;
            }
        }
    }

    if (!didFinish) {
        cout << "A";
    }

    return 0;
}
