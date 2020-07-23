#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string S;
  cin >> S;

  int n    = 0;
  int cnt0 = 0;
  for (auto c : S) {
    if (c - '0' != n) cnt0++;
    n = !n;
  }
  n        = 1;
  int cnt1 = 0;
  for (auto c : S) {
    if (c - '0' != n) cnt1++;
    n = !n;
  }
  cout << min(cnt0, cnt1) << endl;
  return 0;
}
