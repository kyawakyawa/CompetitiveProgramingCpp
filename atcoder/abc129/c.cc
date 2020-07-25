#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  for (int i = 0; i < M; ++i) cin >> a[i];
  vector<int> broken(N + 1, 0);
  for (auto b : a) {
    broken[b] = true;
  }
  vector<int> dp(N + 1, 0);
  dp[0] = 1;

  constexpr int mod = 1000000007;

  for (int i = 0; i < N; ++i) {
    if (!broken[i + 1]) {
      dp[i + 1] += dp[i];
      dp[i + 1] %= mod;
    }
    if (i + 2 <= N && !broken[i + 2]) {
      dp[i + 2] += dp[i];
      dp[i + 2] %= mod;
    }
  }

  cout << dp[N] << endl;
  return 0;
}
