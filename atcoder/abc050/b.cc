#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> T(N);
  for (auto& t : T) {
    cin >> t;
  }
  int M;
  cin >> M;
  vector<int> P(M), X(M);
  for (int i = 0; i < M; ++i) {
    cin >> P[i] >> X[i];
    P[i]--;
  }

  for (int i = 0; i < M; ++i) {
    int tmp = T[P[i]];
    T[P[i]] = X[i];
    cout << accumulate(T.begin(), T.end(), 0) << endl;
    T[P[i]] = tmp;
  }
  return 0;
}
