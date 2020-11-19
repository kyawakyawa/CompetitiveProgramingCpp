#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  int i = 0;
  int l = -1, r = -1;
  for (; i < int(s.size()); ++i) {
    if (l < 0 && s[i] == 'A') {
      l = i;
    }
    if (s[i] == 'Z') {
      r = i;
    }
  }
  cout << r - l + 1 << endl;
  return 0;
}
