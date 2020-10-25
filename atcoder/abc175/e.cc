#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void chmax(int64_t& a, int64_t b) { a = max(a, b); }

int64_t dp[4000][4000][4];

int main(void) {
  int64_t R, C;
  cin >> R >> C;
  int64_t K;
  cin >> K;
  vector<int64_t> r(K), c(K), v(K);
  for (int i = 0; i < K; ++i) {
    cin >> r[i] >> c[i] >> v[i];
    r[i]--;
    c[i]--;
  }
  vector<vector<int>> item(R, vector<int>(C, -1));

  for (int i = 0; i < K; ++i) {
    item[r[i]][c[i]] = i;
  }

  dp[0][0][0] = 0;
  dp[0][0][1] = (item[0][0] >= 0 ? v[item[0][0]] : 0);
  dp[0][0][2] = 0;
  dp[0][0][3] = 0;

  for (int64_t i = 0; i < R; ++i) {
    for (int64_t j = 0; j < C; ++j) {
      for (int64_t k = 0; k < 4; ++k) {
        if (i + 1 < R) {
          if (item[i + 1][j] >= 0) {
            chmax(dp[i + 1][j][1], dp[i][j][k] + v[item[i + 1][j]]);
          }
          chmax(dp[i + 1][j][0], dp[i][j][k]);
        }
        if (j + 1 < C) {
          if (k + 1 < 4 && item[i][j + 1] >= 0) {
            chmax(dp[i][j + 1][k + 1], dp[i][j][k] + v[item[i][j + 1]]);
          }
          chmax(dp[i][j + 1][k], dp[i][j][k]);
        }
      }
    }
  }
  cout << max({dp[R - 1][C - 1][0], dp[R - 1][C - 1][1], dp[R - 1][C - 1][2],
               dp[R - 1][C - 1][3]})
       << endl;

  return 0;
}
