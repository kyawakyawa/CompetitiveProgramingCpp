#include <iostream>

using namespace std;

bool IsPrime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(void) {
  int X;
  cin >> X;
  while (!IsPrime(X)) X++;
  cout << X << endl;
  return 0;
}
