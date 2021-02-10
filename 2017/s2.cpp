#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    uint recordings;    // Number of recordings
    vector<uint> tides; // List of given recordings

    cin >> recordings;

    for (uint i = 0; i < recordings; i++) {
        uint tide;
        cin >> tide;

        tides.push_back(tide);
    }

    std::sort(tides.begin(), tides.end()); // Recordings are ordered generally
    uint slice = recordings % 2 == 0 ? tides.size() / 2
                                     : tides.size() / 2 + 1; // Calculate the positions to slice

    auto low =
        vector<uint>(tides.begin(), tides.begin() + slice); // Low tides are on the first half
    auto high = vector<uint>(tides.begin() + slice, tides.end()); // High tides on the second half

    std::reverse(low.begin(), low.end()); // Low tides go from greatest to least

    for (uint i = 0; i < high.size(); i++) { // Print each tide accordingly
        cout << low[i] << " " << high[i] << " ";
    }

    if (recordings % 2 == 1) { // If an extra low tides exists at the end, print it
        cout << low.back();
    }

    return 0;
}
