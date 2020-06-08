#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <bitset>
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
  vector<vector<int64_t>> m(N, vector<int64_t>(N, 0));

  rep(i, M) {
    int64_t a, b;
    In(a, b);
    a--;
    b--;
    m[a][b] = 1;
    m[b][a] = 1;
  }

  int64_t n1 = N / 2;
  int64_t n2 = N - N / 2;

  vector<int64_t> dp1(int64_t(1) << n1, true);

  rep(i, n1) {
    rep(j, i + 1, n1) {
      if (m[i][j]) {
        int64_t S = ((int64_t(1) << i) | (int64_t(1) << j));
        dp1[S]    = false;
      }
    }
  }

  rep(S, int64_t(1) << n1) {
    if (!dp1[S]) {
      rep(i, n1) { dp1[S | (int64_t(1) << i)] = false; }
    }
  }

  vector<int64_t> dp2(int64_t(1) << n1, 0);
  dp2[0] = ((int64_t(1) << n2) - 1);

  rep(i, n1) {
    int64_t S = (int64_t(1) << i);
    rep(j, N / 2, N) {
      if (!m[i][j]) {
        dp2[S] |= (int64_t(1) << (j - n1));
      }
    }
  }

  rep(S, int64_t(1) << n1) {
    rep(i, n1) {
      bitset<21> bs = S;
      if (!bs[i]) {
        dp2[S | (int64_t(1) << i)] = (dp2[S] & dp2[int64_t(1) << i]);
      }
    }
  }

  vector<int64_t> dp3(int64_t(1) << n2, 0);

  rep(S, int64_t(1) << n2) {
    bitset<21> bs = S;
    dp3[S]        = bs.count();
  }

  rep(i, n2) {
    rep(j, i + 1, n2) {
      if (m[i + n1][j + n1]) {
        int64_t S = (int64_t(1) << i) + (int64_t(1) << j);
        dp3[S]    = 0;
      }
    }
  }

  rep(S, int64_t(1) << n2) {
    if (S > 0 && dp3[S] == 0) {
      rep(i, n2) { dp3[S | (int64_t(1) << i)] = 0; }
    }
  }

  rep(S, int64_t(1) << n2) {
    bitset<21> bs = S;
    rep(i, n2) {
      if (!bs[i]) {
        ChMax(dp3[S | (int64_t(1) << i)], dp3[S]);
      }
    }
  }

  int64_t ans = 0;
  rep(S, int64_t(1) << n1) {
    bitset<21> bs = S;

    if (dp1[S]) {
      ChMax<int64_t>(ans, bs.count() + dp3[dp2[S]]);
    }
  }
  cout << ans << endl;

  return EXIT_SUCCESS;
}
