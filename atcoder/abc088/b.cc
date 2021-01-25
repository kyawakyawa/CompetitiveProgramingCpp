#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), std::greater<int>());

  int A = 0, B = 0;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      A += a[i];
    } else {
      B += a[i];
    }
  }

  cout << A - B << endl;

  return 0;
}
