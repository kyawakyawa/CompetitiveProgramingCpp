#include <iostream>

using namespace std;

int main(void) {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  X -= Z;
  int ans = X / (Y + Z);
  cout << ans << endl;

  return 0;
}
