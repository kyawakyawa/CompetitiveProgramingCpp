#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string S;

  cin >> S;

  bool flags[26];
  for (int i = 0; i < 26; ++i) {
    flags[i] = false;
  }
  for (const auto c : S) {
    int i = c - 'a';
    if (flags[i]) {
      cout << "no" << endl;
      return 0;
    }
    flags[i] = true;
  }

  cout << "yes" << endl;

  return 0;
}
