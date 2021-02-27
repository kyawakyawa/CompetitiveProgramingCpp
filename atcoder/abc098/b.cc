#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;

  for (int i = 0; i < N - 1; ++i) {
    vector<char> X(26, 0);
    for (int j = 0; j < i + 1; ++j) {
      X[S[j] - 'a'] = 1;
    }
    vector<char> Y(26, 0);
    for (int j = i + 1; j < N; ++j) {
      Y[S[j] - 'a'] = 1;
    }
    int tmp = 0;
    for (int j = 0; j < 26; ++j) {
      if (X[j] && Y[j]) {
        tmp++;
      }
    }
    ans = max(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}
