#include <stdint.h>

#include <iostream>

using namespace std;

int main(void) {
  int64_t A, B, C;
  cin >> A >> B >> C;
  const int64_t mod = 1000000007;

  cout << A * B % mod * C % mod << endl;
  return 0;
}

