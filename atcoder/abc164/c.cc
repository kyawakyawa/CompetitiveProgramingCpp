#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  set<string> s;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    s.insert(S);
  }

  cout << s.size() << endl;
  return 0;
}
