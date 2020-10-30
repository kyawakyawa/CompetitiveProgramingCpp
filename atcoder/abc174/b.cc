#include <iostream>

using namespace std;

int main(void) {
  long long N, D;
  cin >> N >> D;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    long long X, Y;
    cin >> X >> Y;
    if (X * X + Y * Y <= D * D) ans++;
  }
  cout << ans << endl;
  return 0;
}
