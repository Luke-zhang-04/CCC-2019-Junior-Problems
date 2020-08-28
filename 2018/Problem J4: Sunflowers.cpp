#include <iostream>
#include <vector>
#include <algorithm>
#define linesLoop(i) for (unsigned int i = 0; i < lines; i++)
#define linesLoop(x) for (unsigned int x = 0; x < lines; x++)

using std::cout;
using std::endl;
using std::cin;
using std::string;

int lines;

std::vector<std::vector<int>> rotate(int deg, std::vector<std::vector<int>> table) {
    std::vector<std::vector<int>> output;
    if (deg == 180) {
        linesLoop(i) {
            std::reverse(table[i].begin(), table[i].end());
        }
        std::reverse(table.begin(), table.end());
    } else if (deg == 90) {
        linesLoop(i) {
            std::vector<int> foo;
            linesLoop(x) {
                foo.push_back(table[table.size()-(x+1)][i]);
            }
            output.push_back(foo);
        }
        return output;
    } else if (deg == 270) {
        linesLoop(i) {
            std::vector<int> foo;
            linesLoop(x) {
                foo.push_back(table[x][table.size()-(i+1)]);
            }
            output.push_back(foo);
        }
        return output;
    }
    return table;
}

int get_degree(std::vector<std::vector<int>> table) {
    linesLoop(i) { //top
        if (table[1][i] < table[0][i]) break;
        bool broken = false;

        for (unsigned int x = 0; x < lines-1; x++) {
            if (table[i][x] < table[i][x+1]) {
                broken = true;
                break;
            }
        }
        if (!broken) {
            if (i == lines-1) return 270;
            continue;
        }
        break;
    }

    linesLoop(i) { //bottom
        if (table[table.size()-2][i] < table[table.size()-1][i]) break;
        bool broken = false;

        for (unsigned int x = 0; x < lines-1; x++) {
            if (table[table.size()-(i+1)][x] > table[table.size()-(i+1)][x+1]) {
                broken = true;
                break;
            }
        }
        if (!broken) {
            if (i == lines-1) return 90;
            continue;
        }
        break;
    }

    linesLoop(i) { //left
        if (table[i][1] < table[i][0]) break;
        bool broken = false;

        for (unsigned int x = 0; x < lines-1; x++) {
            if (table[x][i] > table[x+1][i]) {
                broken = true;
                break;
            }
        }
        if (!broken) {
            if (i == lines-1) return 0;
            continue;
        }
        break;
    }

    linesLoop(i) { //right
        if (table[i][table.size()-2] < table[i][table.size()-1]) break;
        bool broken = false;

        for (unsigned int x = 0; x < lines-1; x++) {
            if (table[x][table.size()-(i+1)] < table[x+1][table.size()-(i+1)]) {
                broken = true;
                break;
            }
        }
        if (!broken) {
            if (i == lines-1) return 180;
            continue;
        }
        break;
    }
    return NULL;
}

int main() {
    cin >> lines;
    std::vector<std::vector<int>> table;
    linesLoop(i) {
        std::vector<int> row;
        linesLoop(x) {
            int a;
            cin >> a;
            row.push_back(a);
        }
        table.push_back(row);
    }

    int degree = get_degree(table);
    std::vector<std::vector<int>> output = rotate(degree, table);
    for (const std::vector<int> &row: output) {
        for (const int & elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
