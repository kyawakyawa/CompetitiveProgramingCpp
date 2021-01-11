#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int ans = 1000000000;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    int cnt = 0;
    while (true) {
      if (A == 0 || A % 2 == 1) {
        break;
      }
      cnt++;
      A /= 2;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
