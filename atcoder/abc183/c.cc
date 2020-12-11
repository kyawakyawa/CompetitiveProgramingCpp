#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> T(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> T[i][j];
    }
  }

  vector<int> p(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    p[i] = i + 1;
  }

  int ans = 0;
  do {
    int cost = 0;
    for (int i = 0; i < N - 2; ++i) {
      cost += T[p[i]][p[i + 1]];
    }
    cost += T[0][p[0]];
    cost += T[p[N - 2]][0];

    if (cost == K) {
      ans++;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;
  return 0;
}
