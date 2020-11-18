#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  int x   = 0;
  for (const auto c : S) {
    if (c == 'I') {
      x++;
    } else {
      x--;
    }
    ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}
