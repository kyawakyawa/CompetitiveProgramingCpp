#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int H, W;
int Ch, Cw, Dh, Dw;
int c[1000][1000];
vector<string> S;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool In(int y, int x) { return (0 <= y && y < H && 0 <= x && x < W); }

bool ChMin(int& a, const int b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main(void) {
  cin >> H >> W;
  cin >> Ch >> Cw >> Dh >> Dw;
  Ch--;
  Cw--;
  Dh--;
  Dw--;

  S.resize(H);
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  const int kInf = 1000000000;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      c[i][j] = kInf;
    }
  }

  using P = pair<int, int>;

  deque<P> que;
  que.emplace_front(Ch, Cw);
  c[Ch][Cw] = 0;
  while (!que.empty()) {
    P now = que.front();
    que.pop_front();

    for (int d = 0; d < 4; ++d) {
      int y = now.first + dx[d];
      int x = now.second + dy[d];
      if (In(y, x) && S[y][x] == '.') {
        if (ChMin(c[y][x], c[now.first][now.second])) {
          que.emplace_front(y, x);
        }
      }
    }

    for (int i = -2; i <= 2; ++i) {
      for (int j = -2; j <= 2; ++j) {
        int y = now.first + i;
        int x = now.second + j;
        if (In(y, x) && S[y][x] == '.') {
          if (ChMin(c[y][x], c[now.first][now.second] + 1)) {
            que.emplace_back(y, x);
          }
        }
      }
    }
  }
  if (c[Dh][Dw] < kInf) {
    cout << c[Dh][Dw] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
