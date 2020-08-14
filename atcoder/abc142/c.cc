#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<pair<int, int>> p(N);
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    p[i] = pair<int, int>(A, i + 1);
  }
  sort(p.begin(), p.end());

  for (const auto &v : p) {
    cout << v.second << " ";
  }
  cout << endl;
  return 0;
}
