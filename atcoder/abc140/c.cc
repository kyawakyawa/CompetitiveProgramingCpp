#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> B(N - 1);
  for (auto &v : B) {
    cin >> v;
  }
  int sum = B[0];

  for (int i = 0; i < N - 2; ++i) {
    sum += min(B[i + 1], B[i]);
  }

  sum += B[N - 2];

  cout << sum << endl;

  return 0;
}
