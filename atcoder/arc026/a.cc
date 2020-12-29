#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int A, B, N;
  cin >> N >> A >> B;

  int ans = 0;
  ans += min(5, N) * B;
  N = max(0, N - 5);
  ans += N * A;
  cout << ans << endl;
  return 0;
}
