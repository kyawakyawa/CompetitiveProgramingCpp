#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  string S;
  cin >> S;
  string T = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";

  vector<string> a = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
  vector<int> d    = {2, 2, 1, 2, 2, 2, 1};

  int j = 0;
  for (int i = 0; i < 7; ++i) {
    if (S == T.substr(j, 20)) {
      cout << a[i] << endl;
      break;
    }
    j += d[i];
  }
  return 0;
}
