#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

#define set std::unordered_set
#define map std::unordered_map

uint rows;
uint columns;
set<uint> visited;
map<uint, vector<uint>> squares;

vector<string> split(string str) {
    vector<string> words;
    std::istringstream ss(str);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

bool solve(uint squareValue) {
    if (squareValue == 1) {
        return true;
    } else if (squares.find(squareValue) == squares.end()) {
        return false;
    }

    for (auto& index : squares.at(squareValue)) {
        if (visited.find(index) == visited.end()) {
            visited.insert(index);
            if (solve(index)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> rows >> columns;
    cin.ignore();

    for (uint i = 0; i < rows; i++) {
        string vals;
        std::getline(cin, vals);

        auto splitVals = split(vals);

        for (uint index = 0; index < splitVals.size(); index++) {
            uint val = std::stoi(splitVals[index]);
            uint squareValue = (i + 1) * (index + 1);

            if (squares.find(val) == squares.end()) {
                vector<uint> coordinateProduct = {squareValue};
                squares.insert(pair<uint, vector<uint>>(val, coordinateProduct));
            } else {
                squares.at(val).push_back(squareValue);
            }
        }
    }

    cout << (solve(rows * columns) ? "yes" : "no") << endl;
}
