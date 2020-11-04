#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> L, R;

vector<int> memo;

const int mod = 998244353;

int dp(int i) {
  if (i < 0) {
    return 0;
  }
  if (memo[i] >= 0) {
    return memo[i];
  }
  if (i == 0) {
    return memo[0] = 1;
  }
  int ret = dp(i - 1);

  for (int k = 0; k < K; ++k) {
    ret += dp(i - L[k]);
    ret %= mod;
    ret -= dp(i - R[k] - 1);
    ret %= mod;
    if (ret < 0) {
      ret += mod;
    }
  }
  return memo[i] = ret;
}

int main(void) {
  cin >> N >> K;
  L.resize(K);
  R.resize(K);
  for (int i = 0; i < K; ++i) {
    cin >> L[i] >> R[i];
  }
  memo.resize(N, -1);
  int mnL = *std::min_element(L.begin(), L.end());
  memo[0] = 1;
  for (int i = 1; i < mnL && i < N; ++i) {
    memo[i] = 0;
  }
  if (mnL < N) {
    memo[mnL] = 1;
  }
  cout << dp(N - 1) << endl;

  return 0;
}
