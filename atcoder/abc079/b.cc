#include <stdint.h>

#include <iostream>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  if (N == 1) {
    cout << 1 << endl;
  } else {
    int64_t L1 = 1;
    int64_t L2 = 2;
    int64_t L  = 1;
    for (int i = 2; i <= N; ++i) {
      L  = L1 + L2;
      L2 = L1;
      L1 = L;
    }
    cout << L << endl;
  }

  return 0;
}
