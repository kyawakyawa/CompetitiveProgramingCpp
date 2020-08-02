#include <stdint.h>

#include <iostream>

using namespace std;

int64_t Gcd(int64_t a, int64_t b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}

int64_t Lcm(int64_t a, int64_t b) { return a / Gcd(a, b) * b; }

int64_t Cnt(int64_t a, int64_t b, int64_t x) {
  int64_t i = (a + x - 1) / x;
  int64_t j = b / x;
  return j - i + 1;
}

int main(void) {
  int64_t A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << B - A + 1 - (Cnt(A, B, C) + Cnt(A, B, D) - Cnt(A, B, Lcm(C, D)))
       << endl;
  return 0;
}
