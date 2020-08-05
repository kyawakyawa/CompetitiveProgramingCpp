#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto& v : A) {
    cin >> v;
  }

  size_t maxi = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    if (A[maxi] < A[i]) {
      maxi = i;
    }
  }
  size_t maxi2 = (maxi == 0 ? 1 : 0);
  for (size_t i = 0; i < A.size(); ++i) {
    if (i != maxi && A[maxi2] < A[i]) {
      maxi2 = i;
    }
  }

  for (size_t i = 0; i < A.size(); ++i) {
    if (i == maxi) {
      cout << A[maxi2] << endl;
    } else {
      cout << A[maxi] << endl;
    }
  }
  return 0;
}
