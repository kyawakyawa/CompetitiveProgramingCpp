#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;

  vector<int> a(N), b(N);
  vector<int> c(M), d(M);

  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < M; ++i) {
    cin >> c[i] >> d[i];
  }

  const auto Dist = [&](int i, int j) {
    return abs(a[i] - c[j]) + abs(b[i] - d[j]);
  };

  for (int i = 0; i < N; ++i) {
    int j     = 0;
    int min_j = 0;
    for (; j < M; ++j) {
      if (Dist(i, min_j) > Dist(i, j)) {
        min_j = j;
      }
    }
    cout << min_j + 1 << endl;
  }

  return 0;
}
