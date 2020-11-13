#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  vector<int64_t> ans;

  for (int64_t i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      ans.emplace_back(i);
      if (i != N / i) {
        ans.emplace_back(N / i);
      }
    }
  }

  sort(ans.begin(), ans.end());

  for (const auto v : ans) {
    cout << v << endl;
  }
  return 0;
}

