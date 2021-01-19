#include <iostream>

using namespace std;

int main(void) {
  int N, A, B;

  cin >> N >> A >> B;

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int j   = i;
    int tmp = 0;
    while (j > 0) {
      tmp += j % 10;
      j /= 10;
    }

    if (A <= tmp && tmp <= B) {
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}
