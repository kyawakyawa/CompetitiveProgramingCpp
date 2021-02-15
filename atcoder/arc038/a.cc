#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<>());

  int ans = 0;
  for (int i = 0; i < N; i += 2) {
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}
