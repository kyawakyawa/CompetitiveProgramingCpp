#include <stdint.h>

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

vector<int64_t> a;

int main(void) {
  int64_t N;
  cin >> N;

  while (N > 0) {
    int64_t m = N % 10;
    N /= 10;

    a.emplace_back(m);
  }

  int ans = -1;
  for (uint64_t S = 0; S < (uint64_t(1) << a.size()); ++S) {
    bitset<64> bs = S;
    if (bs.count() == a.size()) continue;
    int64_t s = 0;
    for (size_t i = 0; i < a.size(); ++i) {
      if (!bs[i]) {
        s += a[i];
      }
    }
    if (s % 3 == 0) {
      if (ans == -1 || int(bs.count()) < ans) {
        ans = int(bs.count());
      }
    }
  }
  cout << ans << endl;

  return 0;
}
