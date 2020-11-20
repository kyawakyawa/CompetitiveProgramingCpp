#include <stdint.h>

#include <iostream>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  int64_t x = 1;
  for (int64_t i = 1; i <= N; ++i) {
    x *= i;
    x %= 1000000007;
  }
  cout << x << endl;

  return 0;
}
