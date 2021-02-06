#include <stdint.h>

#include <iostream>

using namespace std;

int main(void) {
  int64_t r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  if (r1 == r2 && c1 == c2) {
    cout << 0 << endl;
    return 0;
  }

  if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 ||
      abs(r1 - r2) + abs(c1 - c2) <= 3) {
    cout << 1 << endl;
    return 0;
  }

  if ((r1 + c1) % 2 == (r2 + c2) % 2) {
    cout << 2 << endl;
    return 0;
  }

  bool flag = false;
  for (int i = -3; i <= 3; ++i) {
    for (int j = -3; j <= 3; ++j) {
      if (abs(i) + abs(j) > 3) continue;
      int64_t r = r2 + i;
      int64_t c = c2 + j;
      if (r1 + c1 == r + c || r1 - c1 == r - c ||
          abs(r1 - r) + abs(c1 - c) <= 3) {
        flag = true;
      }
    }
  }
  if (flag) {
    cout << 2 << endl;
    return 0;
  }

  cout << 3 << endl;

  return 0;
}
