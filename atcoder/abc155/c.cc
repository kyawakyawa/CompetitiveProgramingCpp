#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  map<string, int> m;

  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    m[S]++;
  }
  int mx = 0;
  for (const auto &v : m) {
    mx = max(mx, v.second);
  }
  for (const auto &v : m) {
    if (v.second == mx) {
      cout << v.first << endl;
    }
  }
  return 0;
}
