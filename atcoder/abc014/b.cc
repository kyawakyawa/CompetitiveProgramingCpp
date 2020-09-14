#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, X;
  cin >> n >> X;
  vector<int> a(n);
  for (auto& v : a) {
    cin >> v;
  }
  int sum       = 0;
  bitset<20> bs = X;
  for (int i = 0; i < n; ++i) {
    if (bs[i]) {
      sum += a[i];
    }
  }
  cout << sum << endl;
  return 0;
}
