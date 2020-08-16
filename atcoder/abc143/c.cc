#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (i == 0 || S[i - 1] != S[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
