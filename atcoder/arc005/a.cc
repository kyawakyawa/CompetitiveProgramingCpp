#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  vector<string> ws(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> ws[i];
  }
  int ans = 0;
  for (auto& w : ws) {
    if (w.back() == '.') {
      w.pop_back();
    }
    if (w == string("Takahashikun") || w == string("TAKAHASHIKUN") ||
        w == string("takahashikun")) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
