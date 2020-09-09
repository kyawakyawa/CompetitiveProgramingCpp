#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
  }
  sort(A.begin(), A.end());
  int mx = A.back();

  while (A.back() == mx) {
    A.pop_back();
  }

  cout << A.back() << endl;
  return 0;
}
