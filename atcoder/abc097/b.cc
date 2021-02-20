#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int X;
  cin >> X;
  int ans = 1;
  for (int b = 2; b <= X; ++b) {
    int tmp = b * b;
    while (tmp <= X) {
      ans = max(ans, tmp);
      tmp *= b;
    }
  }

  cout << ans << endl;
  return 0;
}
