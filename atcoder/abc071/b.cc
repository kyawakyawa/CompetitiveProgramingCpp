#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  string S;
  cin >> S;
  vector<bool> flags(26, 0);
  for (const auto c : S) {
    flags[c - 'a'] = 1;
  }
  for (size_t i = 0; i < 26; ++i) {
    if (flags[i] == 0) {
      cout << char(i + 'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;

  return 0;
}
