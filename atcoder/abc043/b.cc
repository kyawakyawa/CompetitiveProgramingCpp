#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  string ans;

  for (const auto c : s) {
    if (c == '0') {
      ans += c;
    } else if (c == '1') {
      ans += c;
    } else {
      if (!ans.empty()) {
        ans.pop_back();
      }
    }
  }
  cout << ans << endl;

  return 0;
}
