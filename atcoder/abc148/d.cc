#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  for (auto& v : a) {
    cin >> v;
  }
  int ans = 0;
  for (auto v : a) {
    if (ans + 1 == v) ans++;
  }
  if (ans > 0) {
    cout << N - ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
