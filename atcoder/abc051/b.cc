#include <iostream>

using namespace std;

int main(void) {
  int K, S;
  cin >> K >> S;
  int ans = 0;
  for (int X = 0; X <= K; ++X) {
    for (int Y = 0; Y <= K; ++Y) {
      int Z = S - X - Y;
      if (0 <= Z && Z <= K) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
