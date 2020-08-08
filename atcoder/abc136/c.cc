#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> H(N);
  for (auto& v : H) {
    cin >> v;
  }
  for (int i = 0; i < N; ++i) {
    if (i == 0 || H[i - 1] < H[i]) {
      H[i] -= 1;
    }
  }
  bool flag = true;
  for (int i = 1; i < N; ++i) {
    if (H[i - 1] > H[i]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
