#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int m;
    cin >> m;
    ans += max(0, 80 - m);
  }
  cout << ans << endl;
  return 0;
}

