#include <math.h>

#include <iostream>

using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  int a = abs(A - 0);
  int b = abs(B - 0);

  if (a < b) {
    cout << "Ant" << endl;
  } else if (a > b) {
    cout << "Bug" << endl;
  } else {
    cout << "Draw" << endl;
  }
  return 0;
}
