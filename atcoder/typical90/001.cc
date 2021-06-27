#include <stdint.h>

#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

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
  int64_t N, L;
  cin >> N >> L;
  int64_t K;
  cin >> K;
  vector<int64_t> A(N);

  for (auto &a : A) {
    cin >> a;
  }

  int64_t xp1 = LowerBound<int64_t>(1, L, [&](int64_t x) {
    int64_t tmp = 0;
    int64_t cnt = 0;
    for (int64_t i = 0; i < N; ++i) {
      if (A[i] - tmp >= x && L - A[i] >= x) {
        tmp = A[i];
        cnt++;
      }
    }
    return !(cnt >= K);
  });
  cout << xp1 - 1 << endl;
  return 0;
}
