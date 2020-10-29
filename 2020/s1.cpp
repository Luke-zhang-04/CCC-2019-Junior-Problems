#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::tuple;
using std::vector;

bool sort(tuple<uint, int> first, tuple<uint, int> second) {
    return std::get<0>(first) < std::get<0>(second);
}

int main() {
    uint entryCount;
    vector<tuple<uint, int>> entries;
    float fastestSpeed = 0;
    uint previousTime;
    int previousPosition;

    cin >> entryCount;

    for (uint entry = 0; entry < entryCount; entry++) {
        uint time;
        int speed;

        cin >> time >> speed;
        entries.push_back(tuple<uint, int>(time, speed));
    }

    std::sort(entries.begin(), entries.end(), sort);

    previousTime = std::get<0>(entries[0]);
    previousPosition = std::get<1>(entries[0]);

    entries.erase(entries.begin());

    for (auto& entry : entries) {
        uint time = std::get<0>(entry);
        int pos = std::get<1>(entry);

        float speed =
            std::abs(pos - previousPosition) / float(time - previousTime);

        cout << speed << endl;

        previousTime = time;
        previousPosition = pos;

        if (speed > fastestSpeed) {
            fastestSpeed = speed;
        }
    }

    cout << fastestSpeed << endl;

    return 0;
}
