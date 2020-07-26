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

  int ans = 2000000000;
  for (int m = -100; m <= 100; ++m) {
    int cost = 0;
    for (int i = 0; i < N; ++i) {
      cost += (a[i] - m) * (a[i] - m);
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
