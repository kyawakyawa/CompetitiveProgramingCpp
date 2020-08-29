#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for (auto& v : H) {
    cin >> v;
  }
  sort(H.begin(), H.end(), greater<>());
  long long ans = 0;
  for (int i = K; i < N; ++i) {
    ans += H[i];
  }
  cout << ans << endl;
  return 0;
}
