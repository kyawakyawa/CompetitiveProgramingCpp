#include <stdint.h>

#include <iostream>
#include <vector>

using namespace std;

int64_t Head(int64_t n) {
  while (true) {
    if (n / 10 == 0) return n;
    n /= 10;
  }
}

int64_t Tail(int64_t n) { return n % 10; }

int64_t Cnt(int64_t i, int64_t j, int64_t n) {
  int64_t cnt = 0;
  for (int64_t k = 1; k <= n; ++k) {
    if (Head(k) == i && Tail(k) == j) ++cnt;
  }
  return cnt;
}

int main(void) {
  int64_t N;
  cin >> N;

  std::vector<std::vector<int64_t>> cnts(10, std::vector<int64_t>(10, 0));

  for (int64_t i = 1; i < 10; ++i) {
    for (int64_t j = 1; j < 10; ++j) {
      cnts[i][j] = Cnt(i, j, N);
    }
  }

  int64_t ans = 0;
  for (int64_t i = 1; i < 10; ++i) {
    ans += cnts[i][i] * cnts[i][i];
  }

  for (int64_t i = 1; i < 10; ++i) {
    for (int64_t j = i + 1; j < 10; ++j) {
      ans += cnts[i][j] * cnts[j][i] * 2;
    }
  }

  cout << ans << endl;

  return 0;
}
