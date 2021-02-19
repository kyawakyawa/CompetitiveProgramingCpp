#include <stdint.h>

#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int64_t A, B, C;
  cin >> A >> B >> C;
  int K;
  cin >> K;
  if (B < C) {
    swap(B, C);
  }
  if (A < B) {
    swap(A, B);
  }

  for (int i = 0; i < K; ++i) {
    A *= 2;
  }
  cout << A + B + C << endl;

  return 0;
}
