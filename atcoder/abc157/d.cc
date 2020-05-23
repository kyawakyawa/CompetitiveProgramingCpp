#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
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
struct UnionFind {
  vector<T> par;    //親の番号
  vector<T> urank;  //集合のランク
  vector<T> usize;  //集合の要素数
  T num;            //集合の数

  UnionFind() { Init(100000); }

  UnionFind(const T n) { Init(n); }

  void Init(const T n) {  // 0〜n-1までの要素を初期化 最初はバラバラ
    par.clear();
    urank.clear();
    usize.clear();
    par.resize(n);
    urank.resize(n);
    usize.resize(n);
    num = n;
    for (T i = 0; i < n; ++i) {
      par[i]   = i;
      urank[i] = T(0);
      usize[i] = T(1);
    }
  }

  T find(T x) {  // xが属する集合の親を見つける
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }

  T GetSetSize(T x) {  // xが属する集合の要素数を返す。
    return usize[find(x)];
  }

  void Unite(T x, T y) {  // xが属する集合とyが属する集合を併合する。
    x = find(x);
    y = find(y);
    if (x == y) return;

    T s = usize[x] + usize[y];
    num--;
    if (urank[x] < urank[y]) {
      par[x]   = y;
      usize[y] = s;
    } else {
      par[y]   = x;
      usize[x] = s;
      if (urank[x] == urank[y]) urank[x]++;
    }
  }

  bool Same(T x, T y) {  //同じ集合に属するかを判定する
    return find(x) == find(y);
  }

  T NumSet() {  //集合の数(木の数)を返す。
    return num;
  }
};

using Graph = vector<vector<int64_t>>;

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t N, M, K;
  In(N, M, K);
  UnionFind<int64_t> uf_tree(N);

  Graph g1(N), g2(N);

  rep(i, M) {
    int64_t A, B;
    In(A, B);
    A--;
    B--;
    uf_tree.Unite(A, B);
    g1[A].emplace_back(B);
    g1[B].emplace_back(A);
  }

  rep(i, K) {
    int64_t C, D;
    In(C, D);
    C--;
    D--;
    g2[C].emplace_back(D);
    g2[D].emplace_back(C);
  }

  rep(i, N) {
    set<int64_t> s;
    int64_t tmp = 0;
    for (auto v : g1[i]) {
      if (s.find(v) == s.end()) {
        tmp++;
        s.insert(i);
      }
    }
    for (auto v : g2[i]) {
      if (s.find(v) == s.end()) {
        if (uf_tree.Same(v, i)) {
          tmp++;
          s.insert(v);
        }
      }
    }
    cout << uf_tree.GetSetSize(i) - tmp - 1 << " ";
  }

  cout << endl;

  return EXIT_SUCCESS;
}
