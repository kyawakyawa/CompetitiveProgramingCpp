#include <iostream>
#include <string>
#include <vector>

int dx[] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int cnt = 0;
      if (S[i][j] == '#') {
        cout << '#';
        continue;
      }
      for (int d = 0; d < 8; ++d) {
        int i_ = i + dy[d];
        int j_ = j + dx[d];

        if (0 <= i_ && i_ < H && 0 <= j_ && j_ < W && S[i_][j_] == '#') {
          cnt++;
        }
      }
      cout << cnt;
    }
    cout << endl;
  }
  return 0;
}
