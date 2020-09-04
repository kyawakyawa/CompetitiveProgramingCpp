#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(max(n + 1, 4));
  a[1] = 0;
  a[2] = 0;
  a[3] = 1;

  for (int i = 4; i <= n; ++i) {
    a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    a[i] %= 10007;
  }

  cout << a[n] << endl;
  return 0;
}
