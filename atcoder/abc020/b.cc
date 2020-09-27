#include <iostream>

using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;

  int base = 1;
  int tmp  = B;
  while (tmp > 0) {
    base *= 10;
    tmp /= 10;
  }

  cout << 2 * (A * base + B) << endl;
  return 0;
}
