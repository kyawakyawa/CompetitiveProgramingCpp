#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s;
  cin >> s;
  size_t N = s.size();
  size_t l = 0;
  size_t r = N - 1;

  bool flag = true;
  while (l < r) {
    if (s[l] == '*' || s[r] == '*') {
    } else if (s[l] != s[r]) {
      flag = false;
      break;
    }
    l++;
    r--;
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
