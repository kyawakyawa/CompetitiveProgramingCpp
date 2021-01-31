#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int s = n * (n + 1) / 2;

  bool flag = s != 1;

  for (int i = 2; i * i <= s; ++i) {
    if (s % i == 0) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "WANWAN" << endl;
  } else {
    cout << "BOWWOW" << endl;
  }
  return 0;
}
