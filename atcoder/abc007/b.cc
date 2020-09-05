#include <iostream>

using namespace std;

int main(void) {
  string A;
  cin >> A;

  if (A == "a") {
    cout << -1 << endl;
    return 0;
  }

  int n = int(A.size());

  if (n == 1) {
    A[0]--;
  } else {
    A.pop_back();
  }

  cout << A << endl;

  return 0;
}
