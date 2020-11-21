#include <iostream>

using namespace std;

int main(void) {
  int W, a, b;
  cin >> W >> a >> b;

  if (abs(b - a) < 0) {
    cout << 0 << endl;
  } else if (a < b) {
    cout << max(b - (a + W), 0) << endl;
  } else {
    cout << max(a - (b + W), 0) << endl;
  }

  return 0;
}
