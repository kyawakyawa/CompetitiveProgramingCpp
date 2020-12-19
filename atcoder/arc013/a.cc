#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, M, L;
  int P[3];
  cin >> N >> M >> L;
  for (int i = 0; i < 3; ++i) {
    cin >> P[i];
  }

  int ans = 0;

  vector<int> v{0, 1, 2};

  do {
    ans = max(ans, (N / P[v[0]]) * (M / P[v[1]]) * (L / P[v[2]]));
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
  return 0;
}
