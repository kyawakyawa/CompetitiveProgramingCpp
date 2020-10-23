#include <stdint.h>

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  vector<int64_t> h(N + 1, 0);

  for (int64_t i = 1; i < N; ++i) {
    for (int64_t j = 1; j * i < N; ++j) {
      ++h[j * i];
    }
  }
  cout << accumulate(h.begin() + 1, h.end(), int64_t(0)) << endl;
  return 0;
}
