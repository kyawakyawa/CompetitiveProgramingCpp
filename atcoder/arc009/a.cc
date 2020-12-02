#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    ans += a * b;
  }
  cout << int(double(ans) * 1.05) << endl;
  return 0;
}
