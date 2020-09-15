#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &v : A) cin >> v;
  int cnt = 0;
  int sum = 0;
  for (const auto v : A) {
    if (v > 0) {
      cnt++;
      sum += v;
    }
  }

  cout << (sum + cnt - 1) / cnt << std::endl;
  return 0;
}
