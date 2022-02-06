// Partial solution

#include <array>
#include <iostream>
#include <string>
#include <vector>

#define printGrid()                                               \
    for (auto& row : grid) {                                      \
        cout << row[0] << " " << row[1] << " " << row[2] << endl; \
    }
#define expandColumn(colNum) \
    { grid[0][colNum], grid[1][colNum], grid[2][colNum] }

using namespace std;

const int EMPTY = 1e9 + 1;

array<array<int, 3>, 3> grid = {};
uint emptyCount = 0;

int processInput(string input) {
    if (input == "X") {
        emptyCount++;
        return EMPTY;
    }

    return stoi(input);
}

void printGrid_debug() {
    for (auto& row : grid) {
        for (auto& value : row) {
            cout << value << ", ";
        }

        cout << "\n";
    }

    cout << endl;
}

/**
 * @return an array of booleans where true indicates an empty spot, and an integer indicating the
 * number of empty spots
 */
pair<array<bool, 3>, int> emptyPositions(array<int, 3> line) {
    array<bool, 3> positions = {false, false, false};
    uint emptyCount = 0;

    for (uint index = 0; index < 3; index++) {
        if (line[index] == EMPTY) {
            positions[index] = true;
            emptyCount++;
        }
    }

    return make_pair(positions, emptyCount);
}

uint fillSingleRowGaps() {
    uint ops = 0;

    for (auto& row : grid) {
        auto empty = emptyPositions(row);

        if (empty.second == 1) {
            auto positions = empty.first;

            if (positions[0]) {
                row[0] = row[1] - (row[2] - row[1]);
            } else if (positions[1]) {
                row[1] = row[2] - (row[2] - row[0]) / 2;
            } else {
                row[2] = row[1] + (row[1] - row[0]);
            }

            ops++;
        }
    }

    return ops;
}

uint fillSingleColumnGaps() {
    uint ops = 0;

    for (uint colNum = 0; colNum < 3; colNum++) {
        auto empty = emptyPositions(expandColumn(colNum));

        if (empty.second == 1) {
            auto positions = empty.first;

            if (positions[0]) {
                grid[0][colNum] = grid[1][colNum] - (grid[2][colNum] - grid[1][colNum]);
            } else if (positions[1]) {
                grid[1][colNum] = grid[2][colNum] - (grid[2][colNum] - grid[0][colNum]) / 2;
            } else {
                grid[2][colNum] = grid[1][colNum] + (grid[1][colNum] - grid[0][colNum]);
            }

            ops++;
        }
    }

    return ops;
}

uint fillWithCompletedRow() {
    uint ops = 0;
    int fullIndex = 4;

    for (uint index = 0; index < 3; index++) {
        auto empty = emptyPositions(grid[index]);

        if (empty.second == 0) {
            fullIndex = index;

            break;
        }
    }

    if (fullIndex != 4) {
        int increment = grid[fullIndex][1] - grid[fullIndex][0];

        for (uint rowNum = 0; rowNum < 3; rowNum++) {
            if (rowNum == fullIndex) {
                continue;
            }

            auto& row = grid[rowNum];
            auto empty = emptyPositions(row);

            if (empty.second == 2) {
                auto positions = empty.first;

                if (!positions[0]) {
                    row[1] = row[0] + increment;
                    row[2] = row[0] + 2 * increment;
                } else if (!positions[1]) {
                    row[0] = row[1] - increment;
                    row[2] = row[1] + increment;
                } else {
                    row[0] = row[2] - 2 * increment;
                    row[1] = row[2] - increment;
                }

                ops++;
            }
        }
    }

    return ops;
}

int main() {
    for (uint index = 0; index < 3; index++) {
        string val1, val2, val3;

        cin >> val1 >> val2 >> val3;

        grid[index] = {
            processInput(val1),
            processInput(val2),
            processInput(val3),
        };
    }

    uint totalOps = 0;

    while (totalOps < emptyCount) {
        uint newOps = fillSingleRowGaps() + fillSingleColumnGaps() + fillWithCompletedRow();

        if (newOps == 0) {
            break;
        }

        if (newOps == 0) {
            break;
        }

        totalOps += newOps;
    }

    printGrid();

    return 0;
}
