#include <stdint.h>

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int64_t N, X, M;
  cin >> N >> X >> M;

  if (N <= 2 * M) {
    int64_t now = X;
    int64_t ans = 0;
    for (int64_t i = 0; i < N; ++i) {
      ans += now;
      now *= now;
      now %= M;
    }
    cout << ans << endl;
    return 0;
  }

  vector<char> memo(M, 0);
  int64_t now = X;
  int64_t ans = 0;
  int64_t i   = 0;
  for (;; ++i) {
    if (memo[now] == 1) {
      break;
    }
    memo[now] = 1;
    ans += now;
    now *= now;
    now %= M;
  }
  int64_t lp     = now;
  int64_t cnt    = 0;
  int64_t sum_lp = 0;
  for (;;) {
    cnt++;
    sum_lp += now;
    now *= now;
    now %= M;
    if (now == lp) {
      break;
    }
  }
  int64_t k = N - i;
  ans += sum_lp * (k / cnt);
  int64_t l = k % cnt;
  for (int64_t j = 0; j < l; ++j) {
    ans += now;
    now *= now;
    now %= M;
  }
  cout << ans << endl;
  return 0;
}
