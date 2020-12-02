#include <iostream>

using namespace std;

int main(void) {
  int N, M, A, B;
  cin >> N >> M >> A >> B;
  int x = N;
  for (int i = 0; i < M; ++i) {
    int c;
    cin >> c;
    if (x <= A) {
      x += B;
    }
    if (x < c) {
      cout << i + 1 << endl;
      return 0;
    }
    x -= c;
  }
  cout << "complete" << endl;
  return 0;
}
