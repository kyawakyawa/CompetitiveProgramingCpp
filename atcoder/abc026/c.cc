#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> B(N);

  for (int i = 1; i < N; ++i) {
    cin >> B[i];
    B[i]--;
  }

  vector<vector<int>> g(N);

  for (int i = 1; i < N; ++i) {
    g[B[i]].emplace_back(i);
  }

  vector<int> memo(N, -1);

  function<int(int)> Dfs = [&](int i) {
    if (memo[i] >= 0) return memo[i];
    int ret = 1;
    if (g[i].empty()) return ret;
    int mx = 0;
    int mn = 2000000000;
    for (auto v : g[i]) {
      mx = max(mx, Dfs(v));
      mn = min(mn, Dfs(v));
    }
    ret += mx + mn;
    return memo[i] = ret;
  };

  cout << Dfs(0) << endl;

  return 0;
}
