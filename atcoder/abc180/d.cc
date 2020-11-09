#include <iostream>

using namespace std;

int main(void) {
  int64_t X, Y, A, B;
  cin >> X >> Y >> A >> B;

  int64_t ans = 0;

  while (true) {
    if (A < (Y + X - 1) / X && A * X <= X + B) {
      X *= A;
      ans++;
    } else if (X + B < Y) {
      int64_t p = max(int64_t(0), (Y - X + B - 1) / B - 1);
      int64_t a;
      if (X < 2000000000000000000 / (A - 1)) {
        a = X * (A - 1) / B;
      } else {
        a = p;
      }
      a = min(a, p);
      X += a * B;
      ans += a;
    } else {
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
