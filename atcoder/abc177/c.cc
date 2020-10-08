#include <stdint.h>

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (auto &a : A) cin >> a;

  int64_t sum = A.back();
  int64_t ans = 0;
  int64_t mod = 1000000007;
  for (int i = 0; i < N - 1; ++i) {
    int64_t tmp = sum * A[i];
    ans += tmp % mod;
    ans %= mod;
    sum += A[i];
    sum %= mod;
  }
  cout << ans << endl;
  return 0;
}
