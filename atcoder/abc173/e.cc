#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
using default_counter_t = int64_t;

// macro
#define let auto const &
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
constexpr C &Sort(C &a) {
  std::sort(std::begin(a), std::end(a));
  return a;
}
template <class C>
constexpr auto &Min(C const &a) {
  return *std::min_element(std::begin(a), std::end(a));
}
template <class C>
constexpr auto &Max(C const &a) {
  return *std::max_element(std::begin(a), std::end(a));
}
template <class C>
constexpr auto Total(C const &c) {
  return std::accumulate(std::begin(c), std::end(c), C(0));
}
template <typename T>
auto CumSum(std::vector<T> const &v) {
  std::vector<T> a(v.size() + 1, T(0));
  for (std::size_t i = 0; i < a.size() - size_t(1); ++i) a[i + 1] = a[i] + v[i];
  return a;
}
template <typename T>
constexpr bool ChMax(T &a, T const &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
constexpr bool ChMin(T &a, T const &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

void In(void) { return; }

template <typename First, typename... Rest>
void In(First &first, Rest &... rest) {
  cin >> first;
  In(rest...);
  return;
}

template <class T, typename I>
void VectorIn(vector<T> &v, const I n) {
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
inline decltype(auto) MakeNdVector(T n, Args &&... args) noexcept {
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

template <typename T>
struct Combination {
  vector<T> _fact, _rfact, _inv;

  Combination(int64_t sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for (int64_t i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for (int64_t i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for (int64_t i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T Fact(int64_t k) const { return _fact[k]; }

  inline T Rfact(int64_t k) const { return _rfact[k]; }

  inline T Inv(int64_t k) const { return _inv[k]; }

  T P(int64_t n, int64_t r) const {
    if (r < 0 || n < r) return 0;
    return Fact(n) * Rfact(n - r);
  }

  T C(int64_t p, int64_t q) const {
    if (q < 0 || p < q) return 0;
    return Fact(p) * Rfact(q) * Rfact(p - q);
  }

  T H(int64_t n, int64_t r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

template <typename T>
map<T, T> PrimeFactor(T n) {
  map<T, T> ret;
  for (int64_t i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

template <int64_t Mod>
struct ModInt {
  int64_t x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= Mod) x -= Mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += Mod - p.x) >= Mod) x -= Mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = int64_t(1LL * x * p.x % Mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.Inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt Inverse() const {
    int64_t a = x, b = Mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt Pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<Mod>(t);
    return (is);
  }

  static int64_t GetMod() { return Mod; }
};
using P = pair<int64_t, int64_t>;
bool Cm(P a, P b) { return a.first * b.second < a.second * b.first; }

signed main(int argc, char *argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t N, K;
  In(N, K);
  vector<int64_t> A;

  bool zero_flag = false;
  rep(i, N) {
    int64_t tmp;
    In(tmp);
    if (tmp != 0)
      A.emplace_back(tmp);
    else
      zero_flag = true;
  }
  if (int64_t(A.size()) < K) {
    cout << 0 << endl;
    return EXIT_SUCCESS;
  }
  N        = int64_t(A.size());
  using Mi = ModInt<1000000007>;

  if (K % 2 == 1) {
    bool flag = true;
    rep(i, N) {
      if (A[i] > 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ALL(sort, A, greater<int64_t>());
      Mi ans = 1;
      rep(i, K) { ans *= Mi(A[i]); }
      if (zero_flag) {
        cout << 0 << endl;
      } else {
        cout << ans << endl;
      }
      return EXIT_SUCCESS;
    }
  }

  ALL(sort, A,
      [](const int64_t a, const int64_t b) { return abs(a) > abs(b); });

  int64_t cnt_m = 0;
  rep(i, K) {
    if (A[i] < 0) {
      cnt_m++;
    }
  }
  if (cnt_m % 2 == 0 || N == K) {
    Mi ans = 1;
    rep(i, K) { ans *= Mi(A[i]); }
    if (N == K && cnt_m % 2 == 1 && zero_flag) {
      cout << 0 << endl;
    } else
      cout << ans << endl;
    return EXIT_SUCCESS;
  }

  int64_t sw_m = 0, sw_p = 0;
  rep(i, K, N) {
    if (A[i] < 0) {
      sw_m = abs(A[i]);
      break;
    }
  }
  rep(i, K, N) {
    if (A[i] > 0) {
      sw_p = abs(A[i]);
      break;
    }
  }

  int64_t sw_i = 0;
  P mx;
  bool flag = true;
  rep(i, K) {
    if (A[i] < 0 && sw_p > 0) {
      P p(sw_p, abs(A[i]));
      if (flag || Cm(mx, p)) {
        flag = false;
        mx   = p;
        sw_i = i;
      }
    } else if (A[i] > 0 && sw_m > 0) {
      P p(sw_m, abs(A[i]));
      if (flag || Cm(mx, p)) {
        flag = false;
        mx   = p;
        sw_i = i;
      }
    }
  }

  if (A[sw_i] < 0) {
    A[sw_i] = sw_p;
  } else {
    A[sw_i] = -sw_m;
  }
  Mi ans = 1;
  rep(i, K) { ans *= Mi(A[i]); }
  cout << ans << endl;

  return EXIT_SUCCESS;
}
