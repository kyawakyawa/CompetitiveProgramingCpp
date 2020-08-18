#include <math.h>

#include <iostream>

using namespace std;

int main(void) {
  double a, b, x;
  cin >> a >> b >> x;
  const double kPi = M_PI;

  double l = 0, r = kPi / 2.0;

  while (abs(r - l) > 1e-10) {
    double m = (r + l) / 2.0;
    double y = 0.0;
    if (b / tan(m) > a) {
      y = a * a * b - (a * tan(m) * a * a) / 2.0;
    } else {
      y = b / tan(m) * a * b / 2.0;
    }

    if (x < y) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%.10f\n", l * 180.0 / kPi);
  return 0;
}
