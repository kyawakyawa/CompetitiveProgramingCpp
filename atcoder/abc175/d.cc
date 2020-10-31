#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(void) {
  int64_t N, K;
  cin >> N >> K;

  vector<int> P(N);
  vector<int64_t> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    P[i]--;
  }
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }

  int64_t ans = numeric_limits<int64_t>::min();
  for (int s = 0; s < N; ++s) {
    vector<int> vt(N, 0);

    int64_t k = K;

    int now       = s;
    int64_t score = 0;
    while (k > 0) {
      vt[now] = 1;
      now     = P[now];
      score += C[now];
      ans = max(ans, score);
      k--;

      if (vt[now] == 1) {
        break;
      }
    }
    if (k == 0) {
      ans = max(ans, score);
      continue;
    }
    int64_t len = 0;
    int64_t sc  = 0;
    {
      int _now = now;
      while (true) {
        _now = P[_now];
        sc += C[_now];
        len++;
        if (_now == now) break;
      }
    }
    int64_t r = k % len;

    for (int j = 0; j < r; ++j) {
      now = P[now];
      score += C[now];
      k--;
      ans = max(ans, score);
    }
    if (k == 0) {
      ans = max(ans, score);
      continue;
    }

    score += (k / len - 1) * sc;
    ans = max(ans, score);
    for (int j = 0; j < len; ++j) {
      now = P[now];
      score += C[now];
      ans = max(ans, score);
    }
  }
  cout << ans << endl;
  return 0;
}
