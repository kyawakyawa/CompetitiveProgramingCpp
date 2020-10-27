#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<double> A;

int main(void) {
  cin >> N >> K;
  A.resize(N);
  double mn = 0, mx = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  int cnt = 0;
  while (abs(mx - mn) > 1e-7) {
    if (cnt > 300) break;
    const double x = (mx + mn) * 0.5;
    int k          = K;

    bool flag = true;
    for (int i = 0; i < N; ++i) {
      if (A[i] < x) continue;
      int j = int(ceil(A[i] / x));
      k -= j - 1;
      if (k < 0) {
        mn   = x;
        flag = false;
        break;
      }
    }
    if (flag) {
      mx = x;
    }
    ++cnt;
  }
  cout << int(ceil(mx)) << endl;

  return 0;
}
