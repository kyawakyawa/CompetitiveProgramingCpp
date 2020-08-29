#include <stdint.h>

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template <typename T>
constexpr bool ChMin(T& a, T const& b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
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

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> x(n), d(n);

  const int kInf = numeric_limits<int>::max() / 3;

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int _x, _d;
      cin >> _x >> _d;
      _x--;
      x[i].emplace_back(_x);
      d[i].emplace_back(_d);
    }
  }
  const int l = 1050;
  auto dp     = MakeNdVector(n, l, m + 1, int(kInf));
  for (const auto v : x[0]) {
    dp[0][v][0] = 0;
  }
  if (m > 0) {
    for (const auto v : x[1]) {
      dp[1][v][1] = 0;
    }
  }

  for (int i = 1; i < n; ++i) {
    for (size_t p = 0; p < x[i - 1].size(); ++p) {
      const auto u = x[i - 1][p];
      for (size_t q = 0; q < x[i].size(); ++q) {
        const auto v = x[i][q];
        for (int j = 0; j <= m; ++j) {
          ChMin(dp[i][v][j],
                (d[i - 1][p] + d[i][q]) * abs(u - v) + dp[i - 1][u][j]);
        }
      }
    }
    if (i == 1) continue;
    for (size_t p = 0; p < x[i - 2].size(); ++p) {
      const auto u = x[i - 2][p];
      for (size_t q = 0; q < x[i].size(); ++q) {
        const auto v = x[i][q];
        for (int j = 0; j < m; ++j) {
          ChMin(dp[i][v][j + 1],
                (d[i - 2][p] + d[i][q]) * abs(u - v) + dp[i - 2][u][j]);
        }
      }
    }
  }
  int ans = kInf;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j <= m; ++j) {
      ChMin(ans, dp[n - 1][i][j]);
    }
  }
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      ChMin(ans, dp[n - 2][i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
