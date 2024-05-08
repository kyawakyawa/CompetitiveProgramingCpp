#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(void) {
  size_t N;
  cin >> N;
  vector<long long> A, B;
  A.resize(N);
  B.resize(N);

  for (size_t i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }

  long long S = accumulate(A.begin(), A.end(), 0ll);

  long long ans = 0;
  for (size_t i = 0; i < N; ++i) {
    long long tmp = S - A[i] + B[i];
    if (tmp > ans) {
      ans = tmp;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
