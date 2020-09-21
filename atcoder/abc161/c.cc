#include <stdint.h>

#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int64_t N, K;
  cin >> N >> K;

  const int64_t a = N / K;
  const int64_t b = (N + K - 1) / K;

  cout << min(N - K * a, abs(N - K * b)) << endl;

  return 0;
}
