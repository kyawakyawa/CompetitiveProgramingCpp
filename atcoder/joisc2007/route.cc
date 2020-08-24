#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
struct Edge {
  int64_t to;
  T cost;
  Edge(int64_t to_, T cost_) : to(to_), cost(cost_) {}

  T To(void) const { return to; }
  T Cost(void) const { return cost; }
};

template <typename T>
using WeightedGraph = vector<vector<Edge<T>>>;

const int64_t kInf = numeric_limits<int64_t>::max();
template <typename T>
void Dijkstra(const WeightedGraph<T>& graph, int64_t s, vector<T>* dst) {
  dst->clear();
  dst->resize(graph.size());
  fill(dst->begin(), dst->end(), kInf);

  using P = pair<T, int64_t>;

  priority_queue<P, vector<P>, greater<P>> que;

  (*dst)[s] = 0;
  que.push(P(T(0), s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    const int64_t v_id = p.second;

    const T d = (*dst)[v_id];

    if (d < p.first) continue;

    for (const auto& e : graph[v_id]) {
      const auto& nv_id = e.To();
      const T n_cost    = d + e.Cost();
      if ((*dst)[nv_id] <= n_cost) continue;
      (*dst)[nv_id] = n_cost;
      que.push(P((*dst)[nv_id], nv_id));
    }
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  vector<int> a(m), b(m), c(m);

  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }

  WeightedGraph<int64_t> _g(n);
  for (int i = 0; i < m; ++i) {
    _g[a[i]].emplace_back(b[i], c[i]);
    _g[b[i]].emplace_back(a[i], c[i]);
  }

  WeightedGraph<int64_t> g((n + 1) * n);

  for (int i = 0; i < n; ++i) {
    for (size_t j = 0; j < _g[i].size(); ++j) {
      for (size_t k = 0; k < _g[i].size(); ++k) {
        if (j == k) continue;
        int u[2], v[2];
        u[0] = x[_g[i][j].To()] - x[i];
        u[1] = y[_g[i][j].To()] - y[i];

        v[0] = x[_g[i][k].To()] - x[i];
        v[1] = y[_g[i][k].To()] - y[i];

        if (u[0] * v[0] + u[1] * v[1] <= 0) {
          // printf("%ld %ld %ld   %ld %ld\n", _g[i][j].To() + 1, i + 1,
          //        _g[i][k].To() + 1, _g[i][j].To() * n + i,
          //        i * n + _g[i][k].To());
          g[_g[i][j].To() * n + i].emplace_back(i * n + _g[i][k].To(),
                                                _g[i][k].Cost());
        }
      }
    }
  }

  for (size_t i = 0; i < _g[0].size(); ++i) {
    // printf("bb %ld\n", 0 * (n + 1) + _g[0][i].To());
    g[n * n + 0].emplace_back(0 * n + _g[0][i].To(), _g[0][i].Cost());
  }

  vector<int64_t> d(n * (n + 1));
  Dijkstra(g, n * n + 0, &d);

  int64_t ans = kInf;

  for (int i = 0; i < n; ++i) {
    ans = min(ans, d[i * n + 1]);
  }
  if (ans < kInf) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
