#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  int K;
  cin >> K;
  vector<int> P(K);
  for (auto& p : P) cin >> p;
  for (auto& p : P) p--;

  vector<char> used(N, 0);
  used[a] = 1;
  used[b] = 1;

  for (const auto p : P) {
    if (used[p]) {
      cout << "NO" << endl;
      return 0;
    }
    used[p] = 1;
  }
  cout << "YES" << endl;
  return 0;
}
