#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  string c;
  cin >> c;

  stack<int> s;

  for (int i = 0; i < N; ++i) {
    if (c[i] == 'R') {
      s.push(i);
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (c[i] == 'W' && !s.empty()) {
      int j = s.top();
      s.pop();
      if (i < j) {
        swap(c[i], c[j]);
        cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
