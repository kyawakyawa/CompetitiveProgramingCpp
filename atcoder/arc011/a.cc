#include <iostream>

using namespace std;

int main(void) {
  int m, n, N;
  cin >> m >> n >> N;

  int ans   = 0;
  int small = 0;
  while (N > 0) {
    ans += N;
    small += N;

    N = n * (small / m);
    small %= m;
  }
  cout << ans << endl;

  return 0;
}
