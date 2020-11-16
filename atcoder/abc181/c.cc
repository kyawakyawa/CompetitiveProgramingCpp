#include <stdint.h>

#include <iostream>
#include <vector>

using namespace std;

vector<int64_t> x, y;

bool Eq(int64_t i, int64_t j) { return x[i] == x[j] && y[i] == y[j]; }

int main(void) {
  int64_t N;
  cin >> N;

  x.resize(N);
  y.resize(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }

  bool flag = false;
  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = i + 1; j < N; ++j) {
      for (int64_t k = j + 1; k < N; ++k) {
        if (Eq(i, j) || Eq(j, k) || Eq(k, i)) continue;
        int64_t a[2];
        a[0] = x[i] - x[j];
        a[1] = y[i] - y[j];
        int64_t b[2];
        b[0] = x[k] - x[j];
        b[1] = y[k] - y[j];

        int64_t d  = a[0] * b[0] + a[1] * b[1];
        int64_t da = a[0] * a[0] + a[1] * a[1];
        int64_t db = b[0] * b[0] + b[1] * b[1];
        if (d * d == da * db) {
          flag = true;
        }
      }
    }
  }

  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
