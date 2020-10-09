#include <math.h>
#include <stdio.h>

#include <algorithm>

using namespace std;

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);

  n %= 12;

  const double a = n / 12. + (m / 60.) * 1. / 12.;
  const double b = m / 60.;

  const double c = min(abs(a - b), min(a, b) + 1. - max(a, b));

  printf("%.10f\n", c * 360.);
  return 0;
}
