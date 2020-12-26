#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void) {
  int L, R;
  cin >> L >> R;
  vector<int> l(L);
  list<int> r(R);
  for (int i = 0; i < L; ++i) {
    cin >> l[i];
  }
  for (auto& v : r) {
    cin >> v;
  }

  int ans = 0;
  for (int i = 0; i < L; ++i) {
    for (auto it = r.begin(); it != r.end(); it++) {
      if (l[i] == *it) {
        ans++;
        r.erase(it);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
