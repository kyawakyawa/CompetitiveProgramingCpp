#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> ans(N, 0);
  for (size_t i = 1; i < size_t(N); ++i) {
    int A;
    cin >> A;
    A--;
    ans[A]++;
  }

  for (const auto v : ans) {
    cout << v << endl;
  }

  return 0;
}
