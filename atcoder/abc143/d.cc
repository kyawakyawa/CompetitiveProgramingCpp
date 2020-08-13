#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> L(N);
  for (auto &v : L) {
    cin >> v;
  }
  sort(L.begin(), L.end());
  vector<int> cnt(2001, 0);

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = L[i] + 1; j <= 2000; ++j) {
      ans += cnt[j];
    }
    for (int j = 0; j < i; j++) {
      cnt[L[j] + L[i]]++;
    }
  }
  cout << ans << endl;
  return 0;
}
