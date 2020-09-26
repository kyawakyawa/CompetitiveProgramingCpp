#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s;
  cin >> s;
  int cnt    = 0;
  string ans = "";
  for (size_t i = 0; i < s.size(); ++i) {
    cnt++;
    if (i == s.size() - 1 || s[i + 1] != s[i]) {
      ans.push_back(s[i]);
      ans += to_string(cnt);
      cnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
