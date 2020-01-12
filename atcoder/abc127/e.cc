#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using default_counter_t = int;

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
  for (int i = (default_counter_t(b) - default_counter_t(a) - 1) / \
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

int64_t factorial[300000 + 1];          // factorial[n] := n! mod p
int64_t factorial_inverse[300000 + 1];  // factorial_inverse[n] = (n!)^-1 mod p

int64_t extend_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64_t r = a % b;
  int64_t d = extend_gcd(b, r, y, x);
  y -= (a / b) * x;

  return d;
}

void precompute_for_combination(
    int64_t n, int64_t p) {  //前計算 階乗や階乗の逆限を求めておく
  factorial[0] = factorial[1] = 1;
  for (int i = 2; i <= n; i++) {
    factorial[i] = factorial[i - 1] * i % p;
  }

  int64_t y;
  extend_gcd(factorial[n], p, factorial_inverse[n], y);

  factorial_inverse[n] %= p;
  if (factorial_inverse[n] < 0) factorial_inverse[n] = p - factorial_inverse[n];

  for (int64_t i = n; i > 0; i--) {
    factorial_inverse[i - 1] = factorial_inverse[i] * i % p;
  }
}

int64_t combination(int64_t n, int64_t k, int64_t p) {
  if (n < k || n < 0 || k < 0) return 0;  //不正な値
  return factorial[n] % p * factorial_inverse[k] % p *
         factorial_inverse[n - k] % p;
}

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t n, m, k;
  In(n, m, k);
  const int64_t mod = 1000000007;

  precompute_for_combination(n * m, mod);

  int64_t tmp = 0;
  rep(p, m + 1) {
    tmp += p * (m - p) * n % mod;
    tmp %= mod;
  }
  rep(q, n + 1) {
    tmp += q * m * (n - q) % mod;
    tmp %= mod;
  }
  rep(p, 1, m + 1) {
    rep(q, 1, n + 1) {
      tmp += (p + q) * (m - p) * (n - q) * 2 % mod;
      tmp %= mod;
    }
  }
  Out(combination(n * m - 2, k - 2, mod) * tmp % mod);

  return EXIT_SUCCESS;
}
