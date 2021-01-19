#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * Grid of sunflowers
 */
typedef vector<vector<uint>> Grid;

/**
 * Prints grid to stdout
 */
void printGrid(Grid grid) {
    for (auto& row : grid) {
        for (auto& item : row) {
            cout << item << " ";
        }

        cout << endl;
    }
}

/**
 * Rotates grid clockwise by amt degrees (must be a multiple of 90) and returns it
 * @param grid grid to rotate
 * @param amt amount to rotate
 * @returns rotated grid
 */
Grid rotate(Grid grid, uint amt) {
    if (amt == 90) {
        Grid newGrid;

        for (uint index = 0; index < grid.size(); index++) { // For each column in the grid
            vector<uint> newRow;

            // Put all the numbers in one column in a row
            for (auto& row : grid) {
                newRow.push_back(row[row.size() - (index + 1)]);
            }

            newGrid.push_back(newRow);
        }

        return newGrid;
    } else if (amt == 180) {
        Grid newGrid;

        for (auto& row : grid) {
            // Go through each row and reverse the contents
            auto newRow = row;

            std::reverse(newRow.begin(), newRow.end());
            newGrid.push_back(newRow);
        }

        std::reverse(newGrid.begin(), newGrid.end());

        return newGrid;
    } else if (amt == 270) {
        Grid newGrid;

        for (uint index = 0; index < grid.size(); index++) { // For each column in the grid
            vector<uint> newRow;

            // Put all the numbers in one column in a row
            for (auto& row : grid) {
                newRow.push_back(row[index]);
            }

            std::reverse(newRow.begin(), newRow.end());
            newGrid.push_back(newRow);
        }

        return newGrid;
    }

    // amt == 0, return grid
    return grid;
}

/**
 * Tests if grid is a valid sunflower grid by testing each row and then each columns's numbers
 *
 * @param grid grid to test
 * @returns whether or not grid is a valid sunflower grid
 */
bool gridIsValid(Grid grid) {
    // Traverse horizontally and vertically together
    for (uint index = 0; index < grid.size(); index++) {
        for (uint row = 0; row < grid.size() - 1; row++) { // Check vertically
            if (grid[row][index] > grid[row + 1][index]) { // Next value is greater
                return false;
            }
        }

        for (uint column = 0; column < grid.size() - 1; column++) { // Check horizontally
            if (grid[index][column] > grid[index][column + 1]) {    // Next value is greater
                return false;
            }
        }
    }

    return true;
}

int main() {
    uint size;

    cin >> size;

    Grid sunflowers;

    // Collect stdin
    for (uint rowIndex = 0; rowIndex < size; rowIndex++) { // Row
        vector<uint> row;

        for (uint index = 0; index < size; index++) { // Column
            int val;

            cin >> val;

            row.push_back(val);
        }

        sunflowers.push_back(row);
    }

    int orientations[4] = {
        0,
        90,
        180,
        270,
    };

    for (auto& orientation : orientations) {            // Go through each orientation
        auto newGrid = rotate(sunflowers, orientation); // Rotate grid by orientation

        if (gridIsValid(newGrid)) { // Find out if the new orientation is valid
            printGrid(newGrid);

            break;
        }
    }

    return 0;
}
