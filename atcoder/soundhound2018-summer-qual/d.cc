#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using default_counter_t = int64_t;

// macro
#define let auto const&
#define overload4(a, b, c, d, name, ...) name
#define rep1(n) \
  for (default_counter_t i = 0, end_i = default_counter_t(n); i < end_i; ++i)
#define rep2(i, n)                                                           \
  for (default_counter_t i = 0, end_##i = default_counter_t(n); i < end_##i; \
       ++i)
#define rep3(i, a, b)                                    \
  for (default_counter_t i       = default_counter_t(a), \
                         end_##i = default_counter_t(b); \
       i < end_##i; ++i)
#define rep4(i, a, b, c)                                 \
  for (default_counter_t i       = default_counter_t(a), \
                         end_##i = default_counter_t(b); \
       i < end_##i; i += default_counter_t(c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(n) \
  for (default_counter_t i = default_counter_t(n) - 1; i >= 0; --i)
#define rrep2(i, n) \
  for (default_counter_t i = default_counter_t(n) - 1; i >= 0; --i)
#define rrep3(i, a, b)                                         \
  for (default_counter_t i         = default_counter_t(b) - 1, \
                         begin_##i = default_counter_t(a);     \
       i >= begin_##i; --i)
#define rrep4(i, a, b, c)                                          \
  for (default_counter_t                                           \
           i = (default_counter_t(b) - default_counter_t(a) - 1) / \
                   default_counter_t(c) * default_counter_t(c) +   \
               default_counter_t(a),                               \
           begin_##i = default_counter_t(a);                       \
       i >= begin_##i; i -= default_counter_t(c))
#define rrep(...) \
  overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define ALL(f, c, ...)                                           \
  (([&](decltype((c)) cccc) {                                    \
    return (f)(std::begin(cccc), std::end(cccc), ##__VA_ARGS__); \
  })(c))

// function
template <class C>
constexpr C& Sort(C& a) {
  std::sort(std::begin(a), std::end(a));
  return a;
}
template <class C>
constexpr auto& Min(C const& a) {
  return *std::min_element(std::begin(a), std::end(a));
}
template <class C>
constexpr auto& Max(C const& a) {
  return *std::max_element(std::begin(a), std::end(a));
}
template <class C>
constexpr auto Total(C const& c) {
  return std::accumulate(std::begin(c), std::end(c), C(0));
}
template <typename T>
auto CumSum(std::vector<T> const& v) {
  std::vector<T> a(v.size() + 1, T(0));
  for (std::size_t i = 0; i < a.size() - size_t(1); ++i) a[i + 1] = a[i] + v[i];
  return a;
}
template <typename T>
constexpr bool ChMax(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
constexpr bool ChMin(T& a, T const& b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

void In(void) { return; }

template <typename First, typename... Rest>
void In(First& first, Rest&... rest) {
  cin >> first;
  In(rest...);
  return;
}

template <class T, typename I>
void VectorIn(vector<T>& v, const I n) {
  v.resize(size_t(n));
  rep(i, v.size()) cin >> v[i];
}

void Out(void) {
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void Out(First first, Rest... rest) {
  cout << first << " ";
  Out(rest...);
  return;
}

constexpr auto yes(const bool c) { return c ? "yes" : "no"; }
constexpr auto Yes(const bool c) { return c ? "Yes" : "No"; }
constexpr auto YES(const bool c) { return c ? "YES" : "NO"; }

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

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
signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t n, m, s, t;
  In(n, m, s, t);
  s--;
  t--;

  WeightedGraph<int64_t> ga(n), gb(n);

  rep(i, m) {
    int64_t u, v, a, b;
    In(u, v, a, b);
    u--;
    v--;
    ga[u].emplace_back(v, a);
    ga[v].emplace_back(u, a);
    gb[u].emplace_back(v, b);
    gb[v].emplace_back(u, b);
  }

  vector<int64_t> da, db;
  Dijkstra(ga, s, &da);
  Dijkstra(gb, t, &db);

  int64_t mx = 0;

  vector<int64_t> ans;
  rrep(i, n) {
    int64_t en = 1000000000000000;
    en -= da[i];
    int64_t snuuk = en;
    snuuk -= db[i];
    ChMax(mx, snuuk);
    ans.emplace_back(mx);
  }
  ALL(reverse, ans);
  for (auto v : ans) {
    cout << v << endl;
  }
  return EXIT_SUCCESS;
}
