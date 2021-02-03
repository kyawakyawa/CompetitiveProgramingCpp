#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int N, M;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
  }
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; ++i) {
    cin >> t[i];
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    string say = s[i];
    int cnt    = 0;

    for (int j = 0; j < N; ++j) {
      if (say == s[j]) {
        cnt++;
      }
    }
    for (int j = 0; j < M; ++j) {
      if (say == t[j]) {
        cnt--;
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
