#include <iostream>

using namespace std;

int main(void) {
  int N, T;
  cin >> N >> T;

  int ans  = 0;
  int last = 0;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    ans += A + T - max(last, A);
    last = A + T;
  }
  cout << ans << endl;
  return 0;
}

