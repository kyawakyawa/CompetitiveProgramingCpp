#include <iostream>

using namespace std;

int Day(int y, int m, int d) {
  if (m == 1 || m == 2) {
    m = 12 + m;
    y--;
  }
  return 365 * y + (y / 4) - (y / 100) + (y / 400) + ((306 * (m + 1)) / 10) +
         d - 429;
}

int main(void) {
  int y, m, d;
  cin >> y >> m >> d;

  cout << Day(2014, 5, 17) - Day(y, m, d) << endl;

  return 0;
}
