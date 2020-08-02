#include <stdint.h>

#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int64_t W, H, x, y;
  cin >> W >> H >> x >> y;

  cout << double(W * H) / 2.0 << " ";
  if (x * 2 == W && y * 2 == H) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}
