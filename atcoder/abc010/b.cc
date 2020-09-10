#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& v : a) {
    cin >> v;
  }

  int ans = 0;
  for (auto v : a) {
    while (v % 2 == 0 || v % 3 == 2) {
      ans++;
      v--;
    }
  }
  cout << ans << endl;
  return 0;
}
