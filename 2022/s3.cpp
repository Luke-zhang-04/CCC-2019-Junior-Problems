// Get 3 points with brute force soln. TLE for other 3 points.

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

#define set std::unordered_set

uint noteCount, maxPitch, goodSampleCount;

void printNotes(vector<uint> notes) {
    for (auto& note : notes) {
        cout << note << " ";
    }

    cout << endl;
}

vector<uint> fill(uint value, uint size) {
    vector<uint> vec;

    for (uint _ = 0; _ < size; _++) {
        vec.push_back(value);
    }

    return vec;
}

uint getGoodSamples(vector<uint> notes) {
    uint goodSamples = 0;

    for (uint index = 0; index < notes.size(); index++) {
        set<uint> usedNotes;

        for (uint index2 = index; index2 < notes.size(); index2++) {
            if (usedNotes.find(notes[index2]) == usedNotes.end()) {
                usedNotes.insert(notes[index2]);

                goodSamples++;
            } else {
                break;
            }
        }
    }

    return goodSamples;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> noteCount >> maxPitch >> goodSampleCount;

    auto notes = fill(1, noteCount);

    for (uint twoCount = 0; twoCount <= noteCount / 2; twoCount++) {
        for (uint index = 0; index < twoCount && index * 2 < notes.size(); index++) {
            notes[index * 2] = 2;
        }

        if (getGoodSamples(notes) == goodSampleCount) {
            printNotes(notes);

            return 0;
        }

        for (uint index = 0; index < twoCount && index * 2 + 1 < notes.size(); index++) {
            notes[index * 2] = 1;
            notes[index * 2 + 1] = 2;
        }

        if (getGoodSamples(notes) == goodSampleCount) {
            printNotes(notes);

            return 0;
        }

        for (uint index = 0; index < twoCount && index * 2 + 1 < notes.size(); index++) {
            notes[index * 2 + 1] = 1;
        }
    }

    cout << -1 << endl;

    return 0;
}
