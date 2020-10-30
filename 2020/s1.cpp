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

bool sort(tuple<uint, int> first, tuple<uint, int> second) {
    return std::get<0>(first) < std::get<0>(second);
}

int main() {
    uint entryCount;
    vector<tuple<uint, int>> entries;
    float fastestSpeed = 0;

    cin >> entryCount;

    for (uint entry = 0; entry < entryCount; entry++) {
        uint time;
        int position;

        cin >> time >> position;
        entries.push_back(tuple<uint, int>(time, position));
    }

    std::sort(entries.begin(), entries.end(), sort);

    for (unsigned int entry = 0; entry < entryCount - 1; entry++) {
        int distance =
            std::get<1>(entries[entry + 1]) - std::get<1>(entries[entry]);
        float time =
            std::get<0>(entries[entry + 1]) - std::get<0>(entries[entry]);
        float prevSpeed = std::abs(distance) / time;

        fastestSpeed = max(fastestSpeed, prevSpeed);
    }

    cout << fastestSpeed << endl;

    return 0;
}
