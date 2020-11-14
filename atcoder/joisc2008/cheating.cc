#include <stdint.h>

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int64_t n, m;
vector<int64_t> x, y;

template <typename T>
bool C(T d) {
  int64_t cnt_x = 1;

  int64_t left = x[0];
  for (int64_t i = 0; i < m; ++i) {
    if (left + d < x[i]) {
      cnt_x++;
      left = x[i];
    }
  }

  int64_t cnt_y = 1;
  left          = y[0];
  for (int64_t i = 0; i < m; ++i) {
    if (left + d < y[i]) {
      cnt_y++;
      left = y[i];
    }
  }

  return cnt_x + cnt_y <= n;
}

template <typename T>
T LowerBound(T s, T t, function<bool(T)> Comp = C<T>) {
  T lb = s - 1, ub = t;

  while (ub - lb > 1) {
    T mid = (ub + lb) / 2;  // ub lb がともに大きい時オーバフローするので注意

    (Comp(mid) ? ub : lb) = mid;
  }

  return ub;  // ub = t のときはすべてfalse
}

int main(void) {
  cin >> n >> m;

  x.resize(m);
  y.resize(m);

  for (int64_t i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  cout << LowerBound<int64_t>(0, 2000000000) << endl;

  return 0;
}
