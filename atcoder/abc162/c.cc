#include <iostream>

using namespace std;

int64_t Gcd(const int64_t a, const int64_t b) {
  if (b == 0) return a;

  return Gcd(b, a % b);
}

int main(void) {
  int64_t K;
  cin >> K;

  int64_t ans = 0;
  for (int64_t a = 1; a <= K; ++a) {
    for (int64_t b = 1; b <= K; ++b) {
      for (int64_t c = 1; c <= K; ++c) {
        ans += Gcd(Gcd(a, b), c);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
