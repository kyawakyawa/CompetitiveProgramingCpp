#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &v : A) cin >> v;
  sort(A.begin(), A.end());

  for (int i = 0; i < N - 1; ++i) {
    if (A[i] == A[i + 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
