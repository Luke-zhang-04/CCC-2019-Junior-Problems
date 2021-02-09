#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * Gets the sum of all the elements in a vector
 * @tparam T - the type of the elements in a vector
 * @param vec - vector to gather sums for
 * @returns type T - the sum of all the elements
 */
template<typename T>
T sum(vector<T> vec) {
    T total = vec[0];

    for (T& element : vector<T>(vec.begin() + 1, vec.end())) {
        total += element;
    }

    return total;
}

int main() {
    int gameCount; // Number of games played
    cin >> gameCount;

    vector<int> team1; // Scores for team 1
    vector<int> team2; // Scores for team 2

    // Get the score for each game
    for (uint day = 0; day < gameCount; day++) {
        int score;
        cin >> score;

        team1.push_back(score);
    }

    for (uint day = 0; day < gameCount; day++) {
        int score;
        cin >> score;

        team2.push_back(score);
    }

    int team1Sum = sum(team1); // The sum of all the scores
    int team2Sum = sum(team2);

    if (team1Sum == team2Sum) { // If the sums are equal at the end, then output gameCount
        cout << gameCount << endl;

        return 0;
    }

    for (uint index = gameCount - 1; index >= 0; index--) { // Go through scores backwards
        team1Sum -= team1[index];                           // Subtract the sum
        team2Sum -= team2[index];

        if (team1Sum == team2Sum) { // If equal, output index
            cout << index << endl;

            return 0;
        }
    }

    return 0;
}
