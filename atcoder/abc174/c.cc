#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int K;
  cin >> K;
  vector<char> use(K, 0);

  int now = 7;
  int ans = 0;
  for (int i = 1;; ++i) {
    now %= K;
    if (use[now]) {
      ans = -1;
      break;
    }
    use[now] = 1;
    if (now == 0) {
      ans = i;
      break;
    }
    now = now * 10 + 7;
  }
  cout << ans << endl;
  return 0;
}
