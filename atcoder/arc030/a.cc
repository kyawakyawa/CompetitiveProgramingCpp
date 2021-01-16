#include <iostream>

using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;

  if (k == 1 || 2 * k <= n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
