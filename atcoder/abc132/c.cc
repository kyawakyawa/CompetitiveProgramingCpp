#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> d(N);
  for (auto& v : d) {
    cin >> v;
  }
  sort(d.begin(), d.end());

  cout << d[N / 2] - d[N / 2 - 1] << endl;

  return 0;
}
