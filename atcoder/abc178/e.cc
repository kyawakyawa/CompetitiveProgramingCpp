#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < N; ++i) {
    int a = x[i];
    int b = y[i];
    x[i]  = a - b;
    y[i]  = a + b;
  }

  int x_mn = *min_element(x.begin(), x.end());
  int x_mx = *max_element(x.begin(), x.end());
  int y_mn = *min_element(y.begin(), y.end());
  int y_mx = *max_element(y.begin(), y.end());

  cout << max(x_mx - x_mn, y_mx - y_mn) << endl;
  return 0;
}
