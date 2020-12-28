#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  vector<int> D(7);
  vector<int> J(7);
  for (int i = 0; i < 7; ++i) {
    cin >> D[i];
  }
  for (int i = 0; i < 7; ++i) {
    cin >> J[i];
  }
  int ans = 0;

  for (int i = 0; i < 7; ++i) {
    ans += max(D[i], J[i]);
  }
  cout << ans << endl;

  return 0;
}
