#include <iostream>

using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;

  for (int x = 1; x <= 1000000; ++x) {
    if (int(x * 0.08) == A && int(x * 0.10) == B) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
