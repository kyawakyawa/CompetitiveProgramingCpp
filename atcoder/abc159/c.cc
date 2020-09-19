#include <stdint.h>

#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {
  double L;
  cin >> L;

  cout << setprecision(10) << (L / 3) * (L / 3) * (L / 3) << endl;

  return 0;
}
