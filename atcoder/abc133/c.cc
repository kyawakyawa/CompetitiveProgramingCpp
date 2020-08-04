#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int64_t L, R;
  cin >> L >> R;

  vector<int64_t> a;
  a.reserve(2020);
  for (int64_t i = L; i <= R; ++i) {
    if (a.size() > size_t(2019)) break;
    a.emplace_back(i % 2019);
  }

  int64_t ans = 2018;

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = i + 1; j < a.size(); ++j) {
      ans = min(ans, a[i] * a[j] % 2019);
    }
  }
  cout << ans << endl;
  return 0;
}
