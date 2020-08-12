#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> cnts(N, 0);
  for (int i = 0; i < Q; ++i) {
    int A;
    cin >> A;
    cnts[A - 1]++;
  }
  for (const int v : cnts) {
    if (K - (Q - v) <= 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
