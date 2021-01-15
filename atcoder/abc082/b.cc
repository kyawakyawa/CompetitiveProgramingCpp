#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());

  if (s < t) {
    cout << "Yes" << endl;

  } else {
    cout << "No" << endl;
  }
  return 0;
}
