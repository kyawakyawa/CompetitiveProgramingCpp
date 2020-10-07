#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  long long N;
  cin >> N;

  long long ans = 0;
  long long mx  = 0;

  for (long long i = 0; i < N; ++i) {
    long long A;
    cin >> A;

    long long add = max<long long>(0, mx - A);
    ans += add;
    mx = A + add;
  }
  cout << ans << endl;
  return 0;
}
