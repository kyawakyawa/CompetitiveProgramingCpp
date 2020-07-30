#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  int l = 1;
  int r = N;

  for (int i = 0; i < M; ++i) {
    int L, R;
    cin >> L >> R;
    l = max(l, L);
    r = min(r, R);
  }
  cout << max(0, r - l + 1) << endl;
  return 0;
}
