#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  for (auto& v : a) {
    cin >> v;
  }
  const int sum = accumulate(a.begin(), a.end(), 0);

  if (sum % N) {
    cout << -1 << endl;
    return 0;
  }

  const int mean = sum / N;

  int loss = 0;
  int ans  = 0;
  for (int i = 0; i < N - 1; ++i) {
    loss += a[i] - mean;
    if (loss != 0) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
