#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int S;
  cin >> S;

  if (S <= 2) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> dp(S + 1);
  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 0;

  for (int i = 3; i <= S; ++i) {
    dp[i] = dp[i - 3] + dp[i - 1];
    dp[i] %= 1000000007;
  }

  cout << dp[S] << endl;
  return 0;
}
