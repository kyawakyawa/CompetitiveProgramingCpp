#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  for (auto &v : A) cin >> v;

  int ans = A[0] + K - A[N - 1];

  for (int i = 0; i < N - 1; ++i) {
    ans = max(ans, A[i + 1] - A[i]);
  }
  ans = K - ans;

  cout << ans << endl;

  return 0;
}
