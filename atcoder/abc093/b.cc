#include <iostream>
#include <set>

using namespace std;

int main(void) {
  int A, B, K;
  cin >> A >> B >> K;

  set<int> S;

  for (int i = A; i < A + K; ++i) {
    if (i > B) {
      break;
    }
    S.insert(i);
  }

  for (int i = B; i > B - K; i--) {
    if (i < A) {
      break;
    }
    S.insert(i);
  }

  for (auto v : S) {
    cout << v << endl;
  }

  return 0;
}
