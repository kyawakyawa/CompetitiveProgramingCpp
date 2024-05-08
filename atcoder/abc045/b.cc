#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string S[3];
  cin >> S[0] >> S[1] >> S[2];

  reverse(S[0].begin(), S[0].end());
  reverse(S[1].begin(), S[1].end());
  reverse(S[2].begin(), S[2].end());

  uint32_t i = 0;
  while (true) {
    if (S[i].empty()) {
      cout << char('A' + char(i)) << endl;
      break;
    }
    char c = S[i].back();
    S[i].pop_back();
    i = c - 'a';
  }

  return 0;
}
