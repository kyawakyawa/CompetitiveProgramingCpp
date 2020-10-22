#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int W, H, N;
  cin >> W >> H >> N;
  vector<vector<char>> b(H, vector<char>(W, 0));

  for (int k = 0; k < N; ++k) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < x; ++j) {
          b[i][j] = 1;
        }
      }
    } else if (a == 2) {
      for (int i = 0; i < H; ++i) {
        for (int j = x; j < W; ++j) {
          b[i][j] = 1;
        }
      }
    } else if (a == 3) {
      for (int i = 0; i < y; ++i) {
        for (int j = 0; j < W; ++j) {
          b[i][j] = 1;
        }
      }
    } else {
      for (int i = y; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          b[i][j] = 1;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (!b[i][j]) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
