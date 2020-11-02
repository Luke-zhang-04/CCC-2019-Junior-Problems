#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

#define set std::unordered_set
#define map std::unordered_map

uint rows;    // No. of rows
uint columns; // No. of columns

/**
 * Visited squares.
 * We only need one visited set because if the square has been visited we know
 * there's no way that square will take us to the end.
 * This way, we don't look through the same path multiple times.
 */
set<uint> visited;

/**
 * Squares to be stored in the following way:
 * {valueOfSquare: [productOfCoords...]}
 */
map<uint, vector<uint>> squares;

/**
 * Splits str by spaces and returns a vector
 */
vector<string> split(string str) {
    vector<string> words;
    std::istringstream ss(str);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

/**
 * DFS resurcive function to solve problem
 */
bool solve(uint squareValue) {
    // If the value of the square is 1, it can only go to(1, 1).
    // Therefore, we have reached the end.
    if (squareValue == 1) {
        return true;
    } else if (squares.find(squareValue) == squares.end()) { // If square with
                                                             // value doesn't
                                                             // exist, return
        return false;
    }

    for (auto& index : squares[squareValue]) {
        if (visited.find(index) ==
            visited.end()) {       // If square hasn't been visited
            visited.insert(index); // Add to visited
            if (solve(index)) {    // Solve
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> rows >> columns;
    cin.ignore(); // Ignore newline

    for (uint i = 0; i < rows; i++) {
        string vals;
        std::getline(cin, vals);

        auto splitVals = split(vals); // Split input by space

        // Add squares to the squares map
        for (uint index = 0; index < splitVals.size(); index++) {
            uint val = std::stoi(splitVals[index]);
            uint squareValue = (i + 1) * (index + 1);

            if (squares.find(val) == squares.end()) {
                vector<uint> coordinateProduct = {squareValue};
                squares[val] = coordinateProduct;
            } else {
                squares[val].push_back(squareValue);
            }
        }
    }

    cout << (solve(rows * columns) ? "yes" : "no") << endl;
}
