#include <stdint.h>

#include <iostream>

using namespace std;

int64_t ModPow(int64_t x, int64_t n, const int64_t mod) {
  int64_t ret = 1;

  while (n > 0) {
    if (n & 1) {
      ret *= x;
      ret %= mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

int main(void) {
  int64_t N;
  cin >> N;
  const int64_t mod = 1000000007;

  const int64_t ten_n   = ModPow(10, N, mod);
  const int64_t nine_n  = ModPow(9, N, mod);
  const int64_t eight_n = ModPow(8, N, mod);

  cout << (((ten_n + eight_n) % mod + mod) - (2 * nine_n) % mod) % mod << endl;

  return 0;
}
