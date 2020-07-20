#include <stdint.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  vector<string> si(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> si[i];
  }

  map<int64_t, int64_t> m;
  for (const auto &s : si) {
    vector<int> cnt(26, 0);
    for (const auto c : s) {
      cnt[c - 'a']++;
    }
    int64_t h = 0;
    int64_t k = 1;
    for (auto c : cnt) {
      h += k * c;
      k *= 11;
    }
    m[h]++;
  }

  int64_t ans = 0;
  for (auto k : m) {
    if (k.second > 1) {
      ans += k.second * (k.second - 1) / 2;
    }
  }
  cout << ans << endl;
}
