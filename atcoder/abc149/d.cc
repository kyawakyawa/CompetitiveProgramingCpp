#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Cnt(int K, int score, char c, const string& T) {
  vector<char> use(T.size(), 0);

  int ret = 0;
  for (size_t i = 0; i < T.size(); ++i) {
    if (c == T[i]) {
      if (int(i) < K || !use[i - K]) {
        ret += score;
        use[i] = 1;
      }
    }
  }
  return ret;
}

int main(void) {
  int N, K;
  cin >> N >> K;
  int R, S, P;
  cin >> R >> S >> P;
  string T;
  cin >> T;

  int r = Cnt(K, P, 'r', T);
  int s = Cnt(K, R, 's', T);
  int p = Cnt(K, S, 'p', T);

  cout << r + s + p << endl;

  return 0;
}
