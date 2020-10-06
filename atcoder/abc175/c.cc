#include <math.h>
#include <stdint.h>

#include <iostream>

using namespace std;

int main(void) {
  int64_t X, K, D;
  cin >> X >> K >> D;
  X = abs(X);

  const int64_t a = X % D;
  const int64_t b = D - a;
  const int64_t c = X / D;

  if (c > K) {
    cout << X - K * D << endl;
  } else if ((K - c) % 2 == 0) {
    cout << abs(a) << endl;
  } else {
    cout << abs(b) << endl;
  }

  return 0;
}
