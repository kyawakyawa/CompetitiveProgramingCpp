#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> cnt(N, 0);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
  }
  for (int i = 0; i < N; ++i) {
    cout << cnt[i] << endl;
  }

  return 0;
}
