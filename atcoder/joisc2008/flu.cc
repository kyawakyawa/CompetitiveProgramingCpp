#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <queue>
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

int n, m, k, d;
vector<int> x, y;

int w = 1000;
int h = 1000;

bool In(int _y, int _x) { return (0 <= _y && _y < h && 0 <= _x && _x < w); }

int main(void) {
  cin >> n >> m >> d >> k;
  x.resize(n);
  y.resize(n);

  vector<vector<int>> cell(h, vector<int>(w, -1));
  rep(i, n) {
    cin >> x[i] >> y[i];
    cell[y[i]][x[i]] = i;
  }

  vector<char> already(n, 0);
  int ans = 0;

  already[0] = 1;
  if (k < m) {
    ans++;
  }

  queue<int> que;
  que.emplace(0);

  for (int l = 1; l <= k; ++l) {
    queue<int> _que;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (int i = y[v] - d; i <= y[v] + d; ++i) {
        for (int j = x[v] - d; j <= x[v] + d; ++j) {
          int dy = i - y[v];
          int dx = j - x[v];
          if (dy * dy + dx * dx > d * d) {
            continue;
          }
          if (!In(i, j) || cell[i][j] == -1) {
            continue;
          }
          if (already[cell[i][j]]) {
            continue;
          }
          already[cell[i][j]] = 1;
          if (l + m > k) {
            ans++;
          }
          _que.emplace(cell[i][j]);
        }
      }
    }
    que = _que;
  }
  cout << ans << endl;

  return 0;
}
