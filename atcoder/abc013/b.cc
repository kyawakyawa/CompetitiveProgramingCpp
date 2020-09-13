#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;

  int cnt_p = 0, cnt_m = 0;

  int _a = a;

  while (_a != b) {
    _a++;
    _a %= 10;
    cnt_p++;
  }

  _a = a;
  while (_a != b) {
    _a += 9;
    _a %= 10;
    cnt_m++;
  }

  cout << min(cnt_m, cnt_p) << endl;

  return 0;
}
