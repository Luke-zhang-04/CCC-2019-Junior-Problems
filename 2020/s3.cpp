#include <functional>
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

int main() {
    // Get needle and haystack strings
    std::hash<string> hash;
    string needle, haystack;
    cin >> needle >> haystack;

    uint needleLength = needle.size(); // Get needle length now so we don't call len all the time

    /**
     * Map of letters and how many times they appear in the needle
     * E.g aab will be {"a": 2, "b": 1}
     */
    map<char, uint> needleLetters;

    set<long> foundPermutations; // Set of found permutations, to be hashed
    map<char, uint> prevLetters; // Same as needleLetters, but for each part of the haystack
    char prevLetter;             // The last letter of the previous portion of the haystack

    // For each letter in needle, add it to needleLetters
    for (auto& letter : needle) {
        needleLetters[letter] = needleLetters[letter] + 1;
    }

    // "Sliding window" algorithm, with a fixed window size
    for (uint index = 0; index < haystack.size() - needleLength + 1; index++) {
        // Get the letters within the window
        string needleSlice = haystack.substr(index, needleLength);

        /**
         * If no previous letter is found, perform the same loop as performed above.
         * Otherwise, we can use the previous data.
         *
         * We can subtract 1 from the previous window's first letter, and add 1 to the current
         * windows last letter.
         *
         * This way, we don't needlessly loop through needleSlice again.
         */
        if (index == 0) {
            for (auto& letter : needleSlice) {
                prevLetters[letter] = prevLetters[letter] + 1;
            }
        } else {
            // Previous windows first letter
            uint removedLetterValue = prevLetters[prevLetter] - 1;

            // If the subtracted value ends up as 0, just delete it
            if (removedLetterValue == 0) {
                prevLetters.erase(prevLetter);
            } else {
                prevLetters[prevLetter] = removedLetterValue;
            }

            // Add the last letter to prevLetters
            prevLetters[needleSlice[needleLength - 1]] =
                prevLetters[needleSlice[needleLength - 1]] + 1;
        }

        // Assign prevLetter to the first letter of the current window
        prevLetter = needleSlice[0];

        /**
         * We need to use a hashing algorithm, because after test 114, the strings become too
         * large, and we get a memory error in the grader.
         */
        auto hashed = hash(needleSlice);

        // If the two hashmaps are the same, and the hashed slice isn't already found
        if (prevLetters == needleLetters) {
            foundPermutations.insert(hashed);
        }
    }

    cout << foundPermutations.size() << endl;

    return 0;
}
