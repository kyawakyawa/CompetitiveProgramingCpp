#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> v(N);
  for (auto &u : v) {
    cin >> u;
  }

  sort(v.begin(), v.end());

  double a = v[0];

  for (int i = 1; i < N; ++i) {
    a = (a + double(v[i])) / 2.0;
  }

  cout << a << endl;

  return 0;
}
