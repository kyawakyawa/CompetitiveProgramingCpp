#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;

  vector<int> ac(N + 1, 0);
  vector<int> cnt_was(N + 1, 0);

  for (int i = 0; i < M; ++i) {
    int p;
    string S;
    cin >> p >> S;

    if (S == "AC") {
      ac[p] = 1;
    } else {
      if (!ac[p]) {
        cnt_was[p]++;
      }
    }
  }

  int cnt_ac = 0, cnt_wa = 0;
  for (int i = 1; i <= N; ++i) {
    if (ac[i]) {
      cnt_ac++;
      cnt_wa += cnt_was[i];
    }
  }
  cout << cnt_ac << " " << cnt_wa << endl;

  return 0;
}
