#include <iostream>

using namespace std;

int main(void) {
  int64_t A, B;
  cin >> A >> B;
  if (A >= B) {
    cout << "S" << endl;
  } else {
    cout << "K" << endl;
  }
  return 0;
}
