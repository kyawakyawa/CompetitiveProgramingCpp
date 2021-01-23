#include <iostream>
#include <string>

using namespace std;

int main(void) {
  size_t A, B;
  string S;
  cin >> A >> B >> S;

  if (S.size() == A + B + 1) {
    bool flag = true;
    for (size_t i = 0; i < S.size(); ++i) {
      if (i == A) {
        flag &= (S[i] == '-');
      } else {
        flag &= ('0' <= S[i] && S[i] <= '9');
      }
    }
    if (flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}
