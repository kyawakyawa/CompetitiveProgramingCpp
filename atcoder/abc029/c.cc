#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int m = 1;

  for (int i = 0; i < N; ++i) m *= 3;

  for (int i = 0; i < m; ++i) {
    string s;
    int k = i;
    for (int j = 0; j < N; ++j) {
      s.push_back(k % 3 + 'a');
      k /= 3;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}

