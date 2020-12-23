#include <iostream>

using namespace std;

int main(void) {
  string S;
  cin >> S;

  char ICT[] = "ICT";
  char ict[] = "ict";

  int i = 0;
  for (auto c : S) {
    if (i < 3 && (ICT[i] == c || ict[i] == c)) {
      i++;
    }
  }
  if (i == 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
