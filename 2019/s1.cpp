#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    string flips; // Get flip cound
    cin >> flips;

    auto hCount = count(flips.begin(), flips.end(), 'H'); // Get count of "h"
    auto vCount = flips.size() - hCount;                  // Get count of "v"

    vector<vector<int>> grid;

    /**
     * If vCount is even, it's just the grid
     * Otherwise, it's a grid flipped on the vertical axis
     */
    if (vCount % 2 == 0) {
        grid = {{1, 2}, {3, 4}};
    } else {
        grid = {{2, 1}, {4, 3}};
    }

    /**
     * If hCount is even, skip
     * Otherwise, it's a grid flipped on the horizontal axis
     */
    if (hCount % 2 == 1) {
        grid[0].swap(grid[1]);
    }

    cout << grid[0][0] << " " << grid[0][1] << endl << grid[1][0] << " " << grid[1][1] << endl;

    return 0;
}
