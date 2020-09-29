#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<char> used(100001, 0);

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    if (used[A]) ans++;
    used[A] = 1;
  }

  cout << ans << endl;
  return 0;
}
