#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<int> B;
  int g = A[0];
  for (int i = 0; i < N; ++i) {
    g = gcd(g, A[i]);
    if (A[i] > 1) {
      B.emplace_back(A[i]);
    }
  }

  if (B.empty()) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  if (g > 1) {
    cout << "not coprime" << endl;
    return 0;
  }

  int L = *max_element(B.begin(), B.end());

  vector<int> d(L + 1, 0);
  for (size_t i = 0; i < B.size(); ++i) {
    d[B[i]]++;
  }

  vector<int> h(L + 1, 0);
  for (int i = 2; i <= L; ++i) {
    if (h[i] == 0) {
      int cnt = 0;
      for (int j = 1; j * i <= L; ++j) {
        h[j * i] = 1;
        cnt += d[j * i];
      }
      if (cnt > 1) {
        cout << "setwise coprime" << endl;
        return 0;
      }
    }
  }
  cout << "pairwise coprime" << endl;

  return 0;
}
