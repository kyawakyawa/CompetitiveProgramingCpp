#include <deque>
#include <iostream>
#

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  deque<int> t;
  int ans = -1;
  for (int i = 1; i <= N; ++i) {
    int tmp;
    cin >> tmp;
    t.push_back(tmp);
    if (t.size() > 3) {
      t.pop_front();
    }
    if (t.size() < 3) {
      continue;
    }
    int sum = t[0] + t[1] + t[2];
    if (ans == -1 && sum < K) {
      ans = i;
    }
  }
  cout << ans << endl;

  return 0;
}
