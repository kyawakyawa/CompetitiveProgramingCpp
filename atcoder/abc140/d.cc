#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'L') {
      if (i > 0 && S[i - 1] == 'L') {
        cnt++;
      }
    } else {
      if (i + 1 < N && S[i + 1] == 'R') {
        cnt++;
      }
    }
  }
  cout << min(N - 1, cnt + 2 * K) << endl;
  return 0;
}
