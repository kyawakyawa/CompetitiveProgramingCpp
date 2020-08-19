#include <stdint.h>

#include <functional>
#include <iostream>

using namespace std;

int64_t d(int64_t n) {
  int64_t ret = 0;
  while (n > 0) {
    ret++;
    n /= 10;
  }
  return ret;
}

template <typename T>
T LowerBound(T s, T t, function<bool(T)> Comp) {
  T lb = s - 1, ub = t;

  while (ub - lb > 1) {
    T mid = (ub + lb) / 2;  // ub lb がともに大きい時オーバフローするので注意

    (Comp(mid) ? ub : lb) = mid;
  }

  return ub;  // ub = t のときはすべてfalse
}

int main(void) {
  int64_t A, B, X;
  cin >> A >> B >> X;

  auto C = [&](int64_t n) {
    int64_t cost = A * n + B * d(n);
    return cost > X;
  };

  int64_t N = LowerBound<int64_t>(1, 1000000001, C) - 1;

  cout << N << endl;
  return 0;
}
