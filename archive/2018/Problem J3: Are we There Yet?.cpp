#include <iostream>
#include <vector>
#include <valarray>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int indexOf(std::vector<int> array, int target) {
    for (unsigned int i = 0; i < array.size(); i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int sum;
    int zeroIndex;
    int a; int b; int c; int d;
    cin >> a >> b >> c >> d;
    std::vector<int> dists = {0, a, b, c, d};

    for (unsigned int i = 0; i < dists.size(); i++) {
        std::vector<int> output;
        int index = indexOf(dists, 0);

        for (unsigned int x = 0; x < dists.size(); x++) {
            if (dists[x] == 0) {
                output.push_back(0);
            } else if (x < index) {
                sum = 0;
                std::vector<int> iter(dists.begin()+x, dists.begin()+index);
                for (const int &val: iter) {
                    sum += val;
                }
                output.push_back(sum);
            } else {
                sum = 0;
                for (unsigned int val = 0; val < x-index; val++) {
                    sum += dists[val+index+1];
                }
                output.push_back(sum);
            }
        }
        for (const int &x: output) {
            cout << x << " ";
        }
        cout << endl;
        if (i < dists.size()-1) {
            zeroIndex = indexOf(dists, 0);
            dists.erase(dists.begin()+zeroIndex);
            dists.insert(dists.begin()+i+1, 0);
        }
    }
    return 0;
}
