#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
  map<string, int> a;
  a["Sunday"]    = 7;
  a["Saturday"]  = 6;
  a["Friday"]    = 5;
  a["Thursday"]  = 4;
  a["Wednesday"] = 3;
  a["Tuesday"]   = 2;
  a["Monday"]    = 1;

  string day;
  cin >> day;
  cout << max(0, a["Saturday"] - a[day]) << endl;

  return 0;
}
