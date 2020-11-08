#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<set<int>> G;

int main(void) {
  int N, W, H;
  cin >> N >> W >> H;
  vector<vector<int>> C(H, vector<int>(W));

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> C[i][j];
      C[i][j]--;
    }
  }

  G.resize(N);

  for (int i = 0; i < N; ++i) {
    int bmin_x = W - 1;
    int bmin_y = H - 1;
    int bmax_x = 0;
    int bmax_y = 0;

    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        if (C[y][x] == i) {
          bmin_x = min(x, bmin_x);
          bmin_y = min(y, bmin_y);
          bmax_x = max(x, bmax_x);
          bmax_y = max(y, bmax_y);
        }
      }
    }

    for (int y = bmin_y; y <= bmax_y; ++y) {
      for (int x = bmin_x; x <= bmax_x; ++x) {
        if (C[y][x] >= 0 && C[y][x] != i) {
          G[C[y][x]].insert(i);
        }
      }
    }
  }
  vector<int> degs(N, 0);
  vector<size_t> ans;
  queue<int> que;
  for (const auto& u : G) {
    for (const auto v : u) {
      degs[v]++;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (degs[i] == 0) {
      ans.emplace_back(i + 1);
      que.emplace(i);
    }
  }

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (const auto u : G[v]) {
      degs[u]--;
      if (degs[u] == 0) {
        ans.emplace_back(u + 1);
        que.emplace(u);
      }
    }
  }

  reverse(ans.begin(), ans.end());

  for (size_t i = 0; i < ans.size(); ++i) {
    cout << ans[i];
    if (i + 1 < ans.size()) cout << " ";
  }
  cout << endl;
  return 0;
}
