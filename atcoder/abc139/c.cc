#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> H(N);
  for (auto& v : H) {
    cin >> v;
  }

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (H[i] >= H[i + 1]) {
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 0;
    }
  }
  cout << ans << endl;
}
