#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int red  = 0;
  int blue = 0;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    for (auto c : S) {
      if (c == 'R') {
        red++;
      } else if (c == 'B') {
        blue++;
      }
    }
  }
  if (red > blue) {
    cout << "TAKAHASHI" << endl;
  } else if (red < blue) {
    cout << "AOKI" << endl;
  } else {
    cout << "DRAW" << endl;
  }
  return 0;
}
