#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
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

// http://koturn.hatenablog.com/entry/2018/08/01/010000
template <typename T, typename U>
inline std::vector<U> MakeNdVector(T n, U val) noexcept {
  static_assert(std::is_integral<T>::value,
                "[MakeNdVector] The 1st argument must be an integer");
  return std::vector<U>(std::forward<T>(n), std::forward<U>(val));
}

template <typename T, typename... Args>
inline decltype(auto) MakeNdVector(T n, Args&&... args) noexcept {
  static_assert(std::is_integral<T>::value,
                "[MakeNdVector] The 1st argument must be an integer");
  return std::vector<decltype(MakeNdVector(std::forward<Args>(args)...))>(
      std::forward<T>(n), MakeNdVector(std::forward<Args>(args)...));
}

template <typename T, std::size_t N,
          typename std::enable_if<(N > 0), std::nullptr_t>::type = nullptr>
struct NdvectorImpl {
  using type = std::vector<typename NdvectorImpl<T, N - 1>::type>;
};  // struct ndvector_impl

template <typename T>
struct NdvectorImpl<T, 1> {
  using type = std::vector<T>;
};  // struct ndvector_impl

template <typename T, std::size_t N>
using NdVector = typename NdvectorImpl<T, N>::type;

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

int64_t N, M, L;

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

const int64_t kInf = numeric_limits<int64_t>::max() / 8;

using P = pair<int64_t, int64_t>;
void Dijkstra(const WeightedGraph<int64_t>& graph, int64_t s, vector<P>* dst) {
  dst->clear();
  dst->resize(graph.size());
  fill(dst->begin(), dst->end(), P(kInf, 0));

  using Pp = pair<pair<int64_t, int64_t>, int64_t>;

  priority_queue<Pp, vector<Pp>, greater<Pp>> que;

  (*dst)[s] = P(int64_t(0), -L);
  que.push(Pp(P(int64_t(0), -L), s));

  while (!que.empty()) {
    Pp pp = que.top();
    que.pop();
    const int64_t v_id = pp.second;

    const P d = (*dst)[v_id];

    if (d < pp.first) continue;

    for (const auto& e : graph[v_id]) {
      const auto& nv_id = e.To();
      int64_t cnt;
      int64_t r;
      if (-pp.first.second >= e.Cost()) {
        cnt = pp.first.first;
        r   = -pp.first.second - e.Cost();
      } else {
        cnt = pp.first.first + 1;
        r   = L - e.Cost();
      }
      P n_cost = P(cnt, -r);
      if ((*dst)[nv_id] <= n_cost) continue;
      (*dst)[nv_id] = n_cost;
      que.push(Pp((*dst)[nv_id], nv_id));
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
  In(N, M, L);
  WeightedGraph<int64_t> graph(N);

  rep(i, M) {
    int64_t a, b, c;
    In(a, b, c);
    a--;
    b--;
    if (c <= L) {
      graph[a].emplace_back(Edge<int64_t>(b, c));
      graph[b].emplace_back(Edge<int64_t>(a, c));
    }
  }
  vector<vector<P>> tb(N, vector<P>(N));
  rep(i, N) {
    vector<P> dst;
    Dijkstra(graph, i, &dst);
    rep(j, N) { tb[i][j] = dst[j]; }
  }
  int64_t Q;
  In(Q);
  vector<int64_t> s(Q), t(Q);
  rep(i, Q) {
    In(s[i], t[i]);
    s[i]--;
    t[i]--;
  }
  rep(i, Q) {
    int64_t tmp = tb[s[i]][t[i]].first;
    if (tmp < kInf) {
      cout << tmp << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return EXIT_SUCCESS;
}
