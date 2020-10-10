#include <iostream>

using namespace std;

int main(void) {
  int X;
  cin >> X;
  for (int N = 1;; ++N) {
    if (N * N * N * N == X) {
      cout << N << endl;
      break;
    }
  }
  return 0;
}
