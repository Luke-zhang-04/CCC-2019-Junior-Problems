#include <iostream>
using namespace std;

int main() {
    int numb; int rep; cin >> numb >> rep;
    int var = numb; int total = numb;

    for (int i = 1;  i < rep+1; i++) {
        var *= 10;
        total += var;
    }

    cout << total;
}
