#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> l(N);

  for (auto& v : l) {
    cin >> v;
  }

  sort(l.begin(), l.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < K; ++i) {
    ans += l[i];
  }

  cout << ans << endl;

  return 0;
}
