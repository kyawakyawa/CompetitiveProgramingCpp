#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  double ans = 0;
  for (int i = 0; i < N; ++i) {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ans = max(ans, a + b + c + d + e * 110.0 / 900.0);
  }

  printf("%.10f\n", ans);

  return 0;
}
