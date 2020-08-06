#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N);
  for (auto& v : A) cin >> v;
  for (auto& v : B) cin >> v;

  long long cnt = 0;
  for (size_t i = 0; i < B.size(); ++i) {
    int r = min(A[i], B[i]);
    A[i] -= r;
    B[i] -= r;
    cnt += r;
    r = min(A[i + 1], B[i]);
    A[i + 1] -= r;
    B[i] -= r;
    cnt += r;
  }
  cout << cnt << endl;
  return 0;
}
