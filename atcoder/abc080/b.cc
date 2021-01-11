#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  int fn = 0;

  int tmp = N;
  while (tmp > 0) {
    fn += tmp % 10;
    tmp /= 10;
  }

  if (N % fn == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
