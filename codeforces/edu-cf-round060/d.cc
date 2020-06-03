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

template <int64_t Mod>
struct ModInt {
  int64_t x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {}

  ModInt& operator+=(const ModInt& p) {
    if ((x += p.x) >= Mod) x -= Mod;
    return *this;
  }

  ModInt& operator-=(const ModInt& p) {
    if ((x += Mod - p.x) >= Mod) x -= Mod;
    return *this;
  }

  ModInt& operator*=(const ModInt& p) {
    x = int64_t(1LL * x * p.x % Mod);
    return *this;
  }

  ModInt& operator/=(const ModInt& p) {
    *this *= p.Inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt& p) const { return x == p.x; }

  bool operator!=(const ModInt& p) const { return x != p.x; }

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

  friend ostream& operator<<(ostream& os, const ModInt& p) { return os << p.x; }

  friend istream& operator>>(istream& is, ModInt& a) {
    int64_t t;
    is >> t;
    a = ModInt<Mod>(t);
    return (is);
  }

  static int64_t GetMod() { return Mod; }
};

template <typename T>
using Mat = vector<vector<T>>;

template <typename T>
Mat<T> MakeMat(const int64_t m, const int64_t n, const T elm = T(0)) {
  return Mat<T>(m, vector<T>(n, elm));
}

template <typename T>
Mat<T> MakeIdentityMat(const int64_t m, const int64_t n) {
  Mat<T> ret = Mat<T>(m, vector<T>(n));
  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; ++j) {
      ret[i][j] = T(i == j);
    }
  }
  return ret;
}

template <typename T>
Mat<T> MatAdd(const Mat<T>& A, const Mat<T>& B) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());
  if (m != int64_t(B.size()) || n != int64_t(B[0].size())) {
    cerr << "add error" << endl;
    return MakeMat<T>(1, 1);
  }

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; j++) {
      ret[i][j] = A[i][j] + B[i][j];
    }
  }
}

template <typename T>
Mat<T> MatSub(const Mat<T>& A, const Mat<T>& B) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());
  if (m != int64_t(B.size()) || n != int64_t(B[0].size())) {
    cerr << "sub error" << endl;
    return MakeMat<T>(1, 1);
  }

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; j++) {
      ret[i][j] = A[i][j] - B[i][j];
    }
  }
}

template <typename T>
Mat<T> MatMul(const Mat<T>& A, const Mat<T>& B) {
  const int64_t m = int64_t(A.size());
  const int64_t l = int64_t(A[0].size());
  const int64_t n = int64_t(B[0].size());

  if (l != int64_t(B.size())) {
    cerr << "mul error" << endl;
    return MakeMat<T>(1, 1);
  }

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; ++j) {
      for (int64_t k = 0; k < l; ++k) {
        ret[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return ret;
}

template <typename T>
Mat<T> ScalarMulMat(const T a, const Mat<T>& A) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; ++j) {
      ret[i][j] = a * A[i][j];
    }
  }

  return ret;
}

template <typename T>
Mat<T> MatPow(const Mat<T> A, int64_t x) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());

  Mat<T> ret = MakeIdentityMat<T>(m, n);
  Mat<T> tmp = A;
  while (x > 0) {
    if (x & 1) {
      ret = MatMul(ret, tmp);
    }
    tmp = MatMul(tmp, tmp);
    x /= 2;
  }
  return ret;
}
signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t N, M;
  In(N, M);
  if (N < M) {
    cout << 1 << endl;
    return 0;
  }
  using Mi   = ModInt<1000000007>;
  Mat<Mi> x0 = MakeMat<Mi>(M, 1, 1);
  Mat<Mi> A  = MakeMat<Mi>(M, M, Mi(0));

  A[0][0]     = Mi(1);
  A[0][M - 1] = Mi(1);

  rep(i, M - 1) { A[i + 1][i] = Mi(1); }

  int64_t k = N - M + 1;

  Mat<Mi> Ak = MatPow(A, k);

  Mat<Mi> xk = MatMul(Ak, x0);

  cout << xk[0][0].x << endl;

  return EXIT_SUCCESS;
}
