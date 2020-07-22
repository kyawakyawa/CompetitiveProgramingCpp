#include <stdint.h>

#include <iostream>
using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  int64_t a[5];
  for (int64_t i = 0; i < 5; ++i) cin >> a[i];
  int64_t mn = 1000000000000000;

  for (int64_t i = 0; i < 5; ++i) {
    if (a[i] < mn) {
      mn = a[i];
    }
  }
  cout << (N + mn - 1) / mn + 4 << endl;

  return 0;
}
