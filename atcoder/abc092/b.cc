#include <iostream>

using namespace std;

int main(void) {
  int N, D, X;
  cin >> N >> D >> X;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    int d = 1;
    while (d <= D) {
      ans++;
      d += A;
    }
  }
  cout << ans + X << endl;
  return 0;
}
