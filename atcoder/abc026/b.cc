#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<double> R(N);
  for (int i = 0; i < N; ++i) {
    cin >> R[i];
  }
  sort(R.begin(), R.end(), greater<>());
  R.emplace_back(0.);

  double ans = 0;
  for (int i = 0; i < N; ++i) {
    if (i % 2) continue;
    ans += M_PI * (R[i] * R[i] - R[i + 1] * R[i + 1]);
  }
  printf("%.10f\n", ans);
  return 0;
}
