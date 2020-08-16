#include <stdint.h>

#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  int64_t ans = N - 1;
  for (int64_t i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      ans = min(N / i - 1 + i - 1, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
