#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int mn  = numeric_limits<int>::max();
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int P;
    cin >> P;
    if (P <= mn) {
      cnt++;
    }
    mn = min(P, mn);
  }
  cout << cnt << endl;
  return 0;
}
