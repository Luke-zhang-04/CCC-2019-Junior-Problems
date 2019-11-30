#include <iostream>
#include <string>
using namespace std;

int main() {
  int amt = 0;
  int spaces;
  string day1;
  string day2;
  cin >> spaces >> day1 >> day2;

  for (int i=0; i < spaces; i++) if (day1[i] == 'C' && day2[i] == 'C') amt++;
  cout << amt;
  return 0;
}
