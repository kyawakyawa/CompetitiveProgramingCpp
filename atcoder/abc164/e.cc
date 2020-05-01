///////////////////
// https://atcoder.jp/contests/abc164/tasks/abc164_e
#include <iostream>
using namespace std;
///////////////////

#include <algorithm>
#include <cstdint>
#include <limits>
#include <queue>
#include <vector>

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

template <typename T>
void Dijkstra(const WeightedGraph<T>& graph, int64_t s, vector<T>* dst) {
  const T kInf = numeric_limits<T>::max();
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

///////
#define rep(i, n) for (int i = 0; i < (n); i++)

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

using ll = long long;
signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER

  ll n, m, s;
  cin >> n >> m >> s;
  vector<ll> u(m), v(m), a(m), b(m), c(n), d(n);

  ll a_max = numeric_limits<ll>::min();
  rep(i, m) {
    cin >> u[i] >> v[i] >> a[i] >> b[i];
    u[i]--;
    v[i]--;
    a_max = max(a_max, a[i]);
  }

  rep(i, n) { cin >> c[i] >> d[i]; }

  ll p = a_max * (n - 1) + 1;

  WeightedGraph<ll> g(p * n);

  rep(i, m) {
    rep(j, p) {
      if (j < a[i]) continue;
      g[u[i] * p + j].emplace_back(v[i] * p + j - a[i], b[i]);
      g[v[i] * p + j].emplace_back(u[i] * p + j - a[i], b[i]);
    }
  }

  rep(i, n) {
    rep(j, p) { g[i * p + j].emplace_back(i * p + min(p - 1, j + c[i]), d[i]); }
  }

  vector<ll> ans;
  Dijkstra(g, std::min(p - 1, s), &ans);

  rep(i, n) {
    if (i == 0) continue;
    ll min_ = numeric_limits<ll>::max();
    rep(j, p) { min_ = min(min_, ans[i * p + j]); }
    printf("%lld\n", min_);
  }
  return 0;
}
