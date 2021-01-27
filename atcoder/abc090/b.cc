#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;

  int ans = 0;
  for (int i = A; i <= B; ++i) {
    string s;

    int tmp = i;
    while (tmp > 0) {
      s.push_back(char((tmp % 10) - '0'));
      tmp /= 10;
    }
    bool flag = true;
    for (int k = 0; size_t(k) < s.size() / 2; ++k) {
      if (s[k] != s[s.size() - 1 - k]) {
        flag = false;
      }
    }
    if (flag) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
