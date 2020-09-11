#include <string.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string S;
  cin >> S;

  for (auto& c : S) {
    c = char(tolower(c));
  }

  S[0] = char(toupper(S[0]));

  cout << S << endl;
  return 0;
}
