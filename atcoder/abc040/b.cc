#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  int ans = 1000000000;
  for (int i = 1; i <= n; ++i) {
    int j = n / i;
    if (j < 1) continue;
    ans = min(ans, n % i + abs(i - j));
  }
  cout << ans << endl;
  return 0;
}
