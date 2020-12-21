#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  for (int i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
