#include <iostream>
#include <string>

using namespace std;

int main(void) {
  char X;
  cin >> X;
  string s;
  cin >> s;

  string ans = "";
  for (const auto c : s) {
    if (c != X) {
      ans.push_back(c);
    }
  }

  cout << ans << endl;

  return 0;
}

