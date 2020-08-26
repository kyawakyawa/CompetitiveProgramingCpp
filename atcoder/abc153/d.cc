#include <stdint.h>

#include <iostream>

using namespace std;

int64_t f(int64_t h) {
  if (h == 1) return 1;

  return 1 + 2 * f(h / 2);
}

int main(void) {
  int64_t H;
  cin >> H;
  cout << f(H) << endl;
  return 0;
}
