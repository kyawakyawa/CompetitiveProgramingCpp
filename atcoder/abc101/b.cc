#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int S   = 0;
  int tmp = N;
  while (tmp > 0) {
    S += tmp % 10;
    tmp /= 10;
  }

  if (N % S == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
