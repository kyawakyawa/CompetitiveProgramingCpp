#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  for (auto& s : S) {
    cin >> s;
  }

  sort(S.begin(), S.end());

  for (const auto& s : S) {
    cout << s;
  }
  cout << endl;

  return 0;
}
