#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  map<string, int> cnt;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    cnt[S]++;
  }

  int mx     = 0;
  string ans = "";

  for (const auto& v : cnt) {
    if (mx < v.second) {
      ans = v.first;
      mx  = v.second;
    }
  }
  cout << ans << endl;

  return 0;
}
