#include <iostream>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  int ans = K;
  for (int i = 0; i < N - 1; ++i) {
    ans *= (K - 1);
  }
  cout << ans << endl;
  return 0;
}
