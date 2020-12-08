#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s;
  cin >> s;
  for (size_t i = 0; i < s.size(); ++i) {
    if (i % 2 == 0) cout << s[i];
  }
  cout << endl;
  return 0;
}
