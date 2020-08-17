#include <stdint.h>

#include <iostream>

using namespace std;

int64_t Gcd(int64_t a, int64_t b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}

int64_t Lcm(int64_t a, int64_t b) { return a / Gcd(a, b) * b; }

int main(void) {
  int64_t A, B;
  cin >> A >> B;
  cout << Lcm(A, B) << endl;
}
