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

template<typename T>
set<T> make_set(vector<T> vec) {
    set<T> _set;

    for (auto& item : vec) {
        _set.insert(item);
    }

    return _set;
}

vector<uint> uniqueUpTo(uint limit) {
    vector<uint> vec;

    for (uint counter = 1; counter <= noteCount; counter++) {
        vec.push_back(counter > limit ? 1 : counter);
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

struct Piece {
    vector<uint> notes;
    set<uint> unique;
    uint goodSamples;

    Piece(vector<uint> notes) {
        this->notes = notes;
        this->unique = make_set(notes);
        this->goodSamples = getGoodSamples(notes);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> noteCount >> maxPitch >> goodSampleCount;

    Piece min = Piece(uniqueUpTo(1));
    Piece max = Piece(uniqueUpTo(maxPitch));

    if (min.goodSamples == goodSampleCount) {
        printNotes(min.notes);

        return 0;
    } else if (max.goodSamples == goodSampleCount) {
        printNotes(max.notes);

        return 0;
    }

    // Binary search
    vector<uint> closestSolution;
    uint lastChange = (max.unique.size() - min.unique.size()) / 2;
    uint uniqueCount = min.unique.size() + lastChange;

    while (true) {
        vector<uint> notes = uniqueUpTo(uniqueCount);
        Piece piece = Piece(notes);

        if (piece.goodSamples == goodSampleCount) {
            printNotes(piece.notes);

            return 0;
        }

        lastChange /= 2;

        if (lastChange == 1) {
            closestSolution = notes;

            break;
        }

        if (piece.goodSamples > goodSampleCount) {
            uniqueCount -= lastChange;
        } else {
            uniqueCount += lastChange;
        }
    }

    return 0;
}
