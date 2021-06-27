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

int64_t dx[] = {0, 1, 0, -1};
int64_t dy[] = {1, 0, -1, 0};

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
#if 0
  int64_t H, W, K, x1, x2, y1, y2; In(H, W, K, x1, y1, x2, y2); x1--;
  y1--;
  x2--;
  y2--;

  vector<string> c(H);
  rep(i, H) { In(c[i]); }

  auto inside = [&](const int64_t x, const int64_t y) {
    return (0 <= x && x < H && 0 <= y && y < W);
  };

  const int64_t kInf = numeric_limits<int64_t>::max() / 3;

  using P = pair<int64_t, int64_t>;
  queue<P> que;
  que.emplace(x1, y1);
  auto dist    = MakeNdVector(H, W, kInf);
  dist[x1][y1] = 0;

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    rep(k, 4) {
      rep(d, 1, K + 1) {
        int64_t x_ = x + d * dx[k];
        int64_t y_ = y + d * dy[k];
        if (!inside(x_, y_) || c[x_][y_] == '@' || dist[x_][y_] <= dist[x][y])
          break;
        if (dist[x_][y_] == kInf) {
          dist[x_][y_] = dist[x][y] + 1;
          que.emplace(x_, y_);
        }
      }
    }
  }
  if (dist[x2][y2] == kInf) {
    cout << -1 << endl;
  } else {
    cout << dist[x2][y2] << endl;
  }
#else
  int64_t H, W, K, x1, x2, y1, y2;
  In(H, W, K, x1, y1, x2, y2);
  x1--;
  y1--;
  x2--;
  y2--;

  vector<string> c(H);
  rep(i, H) { In(c[i]); }

  auto inside = [&](const int64_t x, const int64_t y) {
    return (0 <= x && x < H && 0 <= y && y < W);
  };

  const int64_t kInf = numeric_limits<int64_t>::max() / 3;

  using P  = pair<int64_t, int64_t>;
  using Pp = pair<P, int64_t>;

  auto dist = MakeNdVector(H, W, 4, kInf);

  priority_queue<pair<int64_t, Pp>, vector<pair<int64_t, Pp>>,
                 greater<pair<int64_t, Pp>>>
      que;
  que.emplace(0, Pp(P(x1, y1), 0));
  que.emplace(0, Pp(P(x1, y1), 1));
  que.emplace(0, Pp(P(x1, y1), 2));
  que.emplace(0, Pp(P(x1, y1), 3));

  dist[x1][y1][0] = 0;
  dist[x1][y1][1] = 0;
  dist[x1][y1][2] = 0;
  dist[x1][y1][3] = 0;

  while (!que.empty()) {
    auto [d, pp] = que.top();
    que.pop();
    auto [xy, dir] = pp;
    auto [x, y]    = xy;

    rep(k, 4) {
      int64_t x_ = x + dx[k];
      int64_t y_ = y + dy[k];
      if (!inside(x_, y_) || c[x_][y_] == '@') continue;
      if (((k xor dir) & 1) == 0) {
        if (ChMin(dist[x_][y_][k], dist[x][y][dir] + 1)) {
          que.emplace(dist[x_][y_][k], Pp(P(x_, y_), k));
        }
      } else {
        int64_t tmp = ((dist[x][y][dir] + K - 1) / K) * K;
        if (ChMin(dist[x_][y_][k], tmp + 1)) {
          que.emplace(dist[x_][y_][k], Pp(P(x_, y_), k));
        }
      }
    }
  }
  bool flag = true;
  rep(k, 4) {
    if (dist[x2][y2][k] < kInf) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << -1 << endl;
  } else {
    int64_t ans = kInf;
    rep(k, 4) { ChMin(ans, ((dist[x2][y2][k] + K - 1) / K)); }
    cout << ans << endl;
  }

#endif

  return EXIT_SUCCESS;
}
