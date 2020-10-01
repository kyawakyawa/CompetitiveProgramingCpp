#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int N, A, B;
  cin >> N >> A >> B;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    string s;
    int d;
    cin >> s >> d;
    int sign = (s == "East" ? 1 : -1);
    ans += sign * min(B, max(A, d));
  }
  if (ans == 0) {
    cout << 0 << endl;
  } else if (ans > 0) {
    cout << "East " << ans << endl;
  } else {
    cout << "West " << -ans << endl;
  }
  return 0;
}
