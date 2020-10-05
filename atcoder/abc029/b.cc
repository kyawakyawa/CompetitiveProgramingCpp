#include <iostream>
#include <numeric>
#include <string>

using namespace std;

int main(void) {
  string S[12];

  for (int i = 0; i < 12; ++i) {
    cin >> S[i];
  }

  cout << accumulate(S, S + 12, 0, [](const int acc, const string s) {
    return acc + int(s.find_first_of('r') != string::npos);
  }) << endl;

  return 0;
}
