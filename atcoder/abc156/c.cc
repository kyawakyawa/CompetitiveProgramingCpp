#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  vector<int> X(N);

  for (auto& v : X) {
    cin >> v;
  }

  int ans = 2000000000;
  for (int P = 1; P <= 100; ++P) {
    int tmp = 0;
    for (const auto v : X) {
      tmp += (v - P) * (v - P);
    }
    ans = min(tmp, ans);
  }

  cout << ans << endl;

  return 0;
}
