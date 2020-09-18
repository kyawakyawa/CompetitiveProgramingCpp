#include <iostream>
#include <string>

using namespace std;

bool Chocku(const string& s) {
  if (s == "") return true;

  const int n = int(s.size());

  if (n > 1 && s[n - 2] == 'c' && s[n - 1] == 'h') {
    return Chocku(s.substr(0, n - 2));
  } else if (s[n - 1] == 'o' || s[n - 1] == 'k' || s[n - 1] == 'u') {
    return Chocku(s.substr(0, n - 1));
  }
  return false;
}

int main(void) {
  string X;
  cin >> X;
  if (Chocku(X)) {
    cout << "YES" << endl;

  } else {
    cout << "NO" << endl;
  }
  return 0;
}
