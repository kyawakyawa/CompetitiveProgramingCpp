#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<int64_t> cum(N, 0);
  cum[0] = A[0];
  for (int i = 1; i < N; ++i) {
    cum[i] = cum[i - 1] + A[i];
  }

  vector<int64_t> mx(N, -1000000000000);
  mx[0] = cum[0];
  for (int i = 1; i < N; ++i) {
    mx[i] = max(mx[i - 1], cum[i]);
  }

  int64_t x   = 0;
  int64_t ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, x + mx[i]);
    x += cum[i];
  }
  cout << ans << endl;

  return 0;
}
