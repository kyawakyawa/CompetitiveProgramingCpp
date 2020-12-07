#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  int mx = 0;
  int mn = 1000;
  for (int i = 0; i < N; ++i) {
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }
  int ans = 1000000000;
  for (int i = 0; i < N; ++i) {
    ans = min(ans, (a[i] - mn) * 2 + mx - a[i]);
    ans = min(ans, a[i] - mn + (mx - a[i]) * 2);
  }
  cout << ans << endl;
  return 0;
}
