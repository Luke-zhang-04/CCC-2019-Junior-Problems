#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::tuple;
using std::vector;

/**
 * Sorting function to sort by first element of a tuple
 */
bool sort(tuple<uint, int> first, tuple<uint, int> second) {
    return std::get<0>(first) < std::get<0>(second);
}

int main() {
    uint entryCount;                  // No. of observations
    vector<tuple<uint, int>> entries; // All observations
    float fastestSpeed = 0;           // Fastest recorded speed

    cin >> entryCount;

    // For number of entries, add the entry to entries[]
    for (uint _ = 0; _ < entryCount; _++) {
        uint time;
        int position;

        cin >> time >> position;
        entries.push_back(tuple<uint, int>(time, position));
    }

    // Sort the entries. Python will sort by first element in the tuple
    std::sort(entries.begin(), entries.end(), sort);

    // Go through each sprint time
    for (unsigned int entry = 0; entry < entryCount - 1; entry++) {
        int distance = std::get<1>(entries[entry + 1]) -
                       std::get<1>(entries[entry]); // Distance covered
        float time = std::get<0>(entries[entry + 1]) -
                     std::get<0>(entries[entry]); // Delta time

        float prevSpeed = std::abs(distance) / time; // v = d / t

        fastestSpeed =
            max(fastestSpeed, prevSpeed); // If this speed is faster, add it.
                                          // Othersise, use old speed
    }

    cout << fastestSpeed << endl;

    return 0;
}
