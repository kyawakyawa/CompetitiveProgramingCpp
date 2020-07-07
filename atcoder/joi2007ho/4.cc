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

template <typename T = int64_t>
struct Edge {
  int64_t to;

  Edge(int64_t to_) : to(to_) {}
};

template <typename T>
using Graph = vector<vector<Edge<T>>>;

/*
 * @return: true -> DAG, false -> DAGでない
 * sorted[i] : i番目の id          (0-indexed)
 * group[i]  : 頂点i は 何位タイか？ (0-indexed)
 */
template <typename T>
bool TopologicalSort(const Graph<T>& graph, vector<int64_t>* sorted,
                     vector<int64_t>* group = nullptr) {
  sorted->clear();
  sorted->reserve(graph.size());
  if (group != nullptr) {
    group->clear();
    group->resize(graph.size(), -1);
  }

  using P = pair<int64_t, int64_t>;

  vector<int64_t> degs(graph.size(), 0);
  queue<P> que;
  for (const auto& v : graph) {
    for (const auto& e : v) {
      degs[e.to]++;
    }
  }

  for (size_t v_id = 0; v_id < graph.size(); ++v_id) {
    if (degs[v_id] == 0) {
      que.emplace(v_id, 0);
    }
  }

  while (!que.empty()) {
    const int64_t v_id = que.front().first;
    const int64_t g_id = que.front().second;
    que.pop();
    sorted->emplace_back(v_id);
    if (group != nullptr) {
      (*group)[v_id] = g_id;
    }

    for (const auto& e : graph[v_id]) {
      degs[e.to]--;
      if (degs[e.to] == 0) {
        que.emplace(e.to, g_id + 1);
      }
    }
  }

  return sorted->size() == graph.size();
}

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t n, m;
  In(n, m);
  Graph<Edge<int64_t>> graph(n);

  rep(k, m) {
    int64_t i, j;
    In(i, j);
    i--;
    j--;
    graph[i].emplace_back(j);
  }
  vector<int64_t> sorted, group;

  TopologicalSort(graph, &sorted, &group);
  for (auto v : sorted) {
    cout << v + 1 << endl;
  }
  int64_t mx = *max_element(group.begin(), group.end());

  if (mx == n - 1) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }

  return EXIT_SUCCESS;
}
