#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
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
struct RAQ {
  int64_t n;
  int64_t k;  //バケットの数
  T sqrt_n;   //バケットの大きさ
  vector<T> data;
  vector<T> bucket_sum;

  RAQ() = delete;
  RAQ(const int64_t n_, const int64_t sqrt_n_ = 1000) {
    Initialize(n_, sqrt_n_);
  }

  void Initialize(const int64_t n_, const int64_t sqrt_n_ = 1000) {
    n = n_;

    sqrt_n = sqrt_n_;

    k = (n + sqrt_n - 1) / sqrt_n;  //切り上げ割り算

    data.clear();
    bucket_sum.clear();

    data.resize(k * sqrt_n, 0);
    bucket_sum.resize(k, 0);
  }

  void Add(const int64_t a, const int64_t b,
           const T x) {  //[a,b)(0-indexed)にx を加算
    if (a >= sqrt_n * k || b > sqrt_n * k) {
      cerr << "error index k" << endl;
      return;
    }
    if (a >= n || b > n) {
      cerr << "warning index k" << endl;
    }

    for (int64_t i = 0; i < k; ++i) {
      int64_t l = i * sqrt_n, r = (i + 1) * sqrt_n;
      if (b <= l || r <= a) continue;
      if (l < a || b < r) {
        for (int64_t j = max(l, a); j < min(b, r); ++j) {
          data[j] += x;
        }
      } else {
        bucket_sum[i] += x;
      }
    }
  }

  T Get(const int64_t i) {  // i番目(0-indexed)の値を取得する
    return data[i] + bucket_sum[i / sqrt_n];
  }
};

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t N, D, A;
  In(N, D, A);
  using P = pair<int64_t, int64_t>;
  vector<P> XH(N);
  rep(i, N) { In(XH[i].first, XH[i].second); }

  Sort(XH);

  vector<int64_t> X(N);

  rep(i, N) { X[i] = XH[i].first; }

  RAQ<int64_t> raq(N);

  rep(i, N) { raq.Add(i, i + 1, XH[i].second); }

  int64_t ans = 0;
  rep(i, N) {
    int64_t rd = raq.Get(i);
    if (rd <= 0) continue;
    auto it   = upper_bound(X.begin() + i, X.end(), X[i] + 2 * D);
    int64_t j = (it - X.begin());

    raq.Add(i, j, -((rd + A - 1) / A) * A);
    ans += (rd + A - 1) / A;
  }
  cout << ans << endl;

  return EXIT_SUCCESS;
}
