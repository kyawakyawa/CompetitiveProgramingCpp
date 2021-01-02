#include <stdint.h>

#include <iostream>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  int64_t x = 1;
  while ((x + 1) * (x + 1) <= N) {
    x++;
  }
  cout << x * x << endl;
  return 0;
}
