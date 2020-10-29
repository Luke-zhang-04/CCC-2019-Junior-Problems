#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::vector<string> output(string str) {
    int index = 0;
    int index2;
    int count;
    string portion;
    std::vector<string> out_list;
    str.append(" ");

    while (true) {
        count = 0;
        for (unsigned int i = index; i < str.length(); i++) {
            if (str[i] != str[index]) {
                index2 = i-1;
                break;
            }
            count++;
        }
        if (index2 - index > 0) {
            portion = str.substr(index, index2-index);
        } else {
            portion = str[index];
            index2++;
        }
        out_list.push_back(std::to_string(count));
        string out;
        out += portion[0];
        out_list.push_back(out);

        index += count;

        if (index+1 == str.length()) {
            break;
        }
    }
    return out_list;
}

int main() {
    string n;
    getline(cin, n);
    cin.clear();
    string lines[std::stoi(n)];

    for (unsigned int i = 0; i < std::stoi(n); i++) {
        string a;
        getline(cin, a);
        lines[i] = a;
    }

    for (const string &i: lines) {
        std::vector<string> res = output(i);
        for (const string &x: res) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
