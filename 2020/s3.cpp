#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define set std::unordered_set
#define map std::unordered_map

map<char, uint> getLetters(string str) {
    map<char, uint> letters;

    for (auto& letter : str) {
        if (letters.find(letter) == letters.end()) {
            letters[letter] = 1;
        } else {
            letters[letter] = letters[letter] + 1;
        }
    }

    return letters;
}

int main() {
    string needle, haystack;
    cin >> needle >> haystack;

    uint needleLength = needle.size();
    auto needleLetters = getLetters(needle);
    set<string> foundPermutations;

    for (uint index = 0; index < haystack.size() - needleLength + 1; index++) {
        string needleSlice = haystack.substr(index, needleLength);

        if (getLetters(needleSlice) == needleLetters &&
            foundPermutations.find(needleSlice) == foundPermutations.end()) {
            foundPermutations.insert(needleSlice);
        }
    }

    cout << foundPermutations.size() << endl;

    return 0;
}
