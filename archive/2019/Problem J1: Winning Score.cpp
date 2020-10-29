#include <iostream>
using namespace std;

inline int score(int a, int b, int c) {
    return 3 * a + 2 * b + c;
}

int main() {
    int arg1;
    int arg2;
    int arg3;
    int arg4;
    int arg5;
    int arg6;
    cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5 >> arg6;
    int aScore = score(arg1, arg2, arg3);
    int bScore = score(arg4, arg5, arg6);

    if (aScore > bScore)
        cout << "A";
    else if (bScore > aScore)
        cout << "B";
    else if (bScore == aScore)
        cout << "T";
}
