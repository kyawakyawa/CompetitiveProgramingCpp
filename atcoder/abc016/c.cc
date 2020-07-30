#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> g;
vector<int> visit;

int main(void) {
  cin >> N >> M;
  g.resize(N);
  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    g[A].emplace_back(B);
    g[B].emplace_back(A);
  }
  visit.resize(N);
  for (int i = 0; i < N; ++i) {
    fill(visit.begin(), visit.end(), 0);
    visit[i] = true;
    queue<pair<int, int>> que;
    que.emplace(i, 0);
    int cnt = 0;
    while (!que.empty()) {
      auto p = que.front();
      que.pop();
      for (auto v : g[p.first]) {
        if (!visit[v] && p.second < 2) {
          visit[v] = true;
          que.emplace(v, p.second + 1);
          if (p.second + 1 == 2) cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
