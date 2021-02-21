#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int N, M, X;
  cin >> N >> M >> X;

  int l = 0, r = 0;
  for (int i = 0; i < M; ++i) {
    int A;
    cin >> A;
    if (A < X) {
      l++;
    } else {
      r++;
    }
  }

  cout << min(l, r) << endl;

  return 0;
}
