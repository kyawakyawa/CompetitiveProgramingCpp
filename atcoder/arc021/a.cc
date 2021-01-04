#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool In(int i) { return 0 <= i && i < 4; }
int main(void) {
  vector<vector<int>> A(4, vector<int>(4));

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> A[i][j];
    }
  }

  bool flag = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int d = 0; d < 4; ++d) {
        int x = j + dx[d];
        int y = i + dy[d];
        if (In(x) && In(y) && A[i][j] == A[y][x]) {
          flag = true;
        }
      }
    }
  }
  if (flag) {
    cout << "CONTINUE" << endl;
  } else {
    cout << "GAMEOVER" << endl;
  }

  return 0;
}
