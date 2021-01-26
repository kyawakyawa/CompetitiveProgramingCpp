#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  bool four = false;
  for (int i = 0; i < N; ++i) {
    char S;
    cin >> S;
    if (S == 'Y') {
      four = true;
      break;
    }
  }
  if (four) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
  return 0;
}
