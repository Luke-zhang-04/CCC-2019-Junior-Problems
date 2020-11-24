#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    cout << std::fixed
         << std::setprecision(1); // Set output presicion to 1 digit

    int villageCount;     // No of villages
    vector<int> villages; // All village positions

    cin >> villageCount;

    for (uint i = 0; i < villageCount; i++) { // Get positions and add to vector
        int pos;

        cin >> pos;
        villages.push_back(pos);
    }

    std::sort(villages.begin(), villages.end()); // Sort villages

    _Float64 smallestDistance = 0; // Keep track of smallest neighbourhood
    _Float64 prevDistance = 0;     // Keep previously computed distance

    // We can't use range based loop b/c we also need the index
    for (uint index = 1; index < villageCount - 1; index++) {
        auto val = villages[index];

        if (prevDistance == 0) {
            prevDistance = (_Float64(val) - villages[index - 1]) / 2;
        }

        auto leftDistance = prevDistance; // Distance from left of the village
        auto rightDistance =
            (villages[index + 1] - _Float64(val)) / 2; // Distance from right
        auto totalDistance =
            leftDistance + rightDistance; // Total neighbourhood size

        // Assign smallest distance if this distance is smaller
        if (smallestDistance == 0 || totalDistance < smallestDistance) {
            smallestDistance = totalDistance;
        }

        if (smallestDistance == 1) { // Break at smallest distance
            break;
        }

        prevDistance = rightDistance; // Set prevDistance to the right distance
    }

    cout << smallestDistance << endl;
}
