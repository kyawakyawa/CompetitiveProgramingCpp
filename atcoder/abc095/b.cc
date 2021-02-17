#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  int N, X;
  cin >> N >> X;

  vector<int> m(N);
  for (int i = 0; i < N; ++i) {
    cin >> m[i];
  }
  sort(m.begin(), m.end());

  X -= accumulate(m.begin(), m.end(), 0,
                  [](const int acc, int v) { return acc + v; });

  cout << X / m[0] + N << endl;
  return 0;
}
