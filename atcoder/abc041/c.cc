#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<pair<int, int>> a(N);
  {
    int i = 0;
    for (auto& v : a) {
      cin >> v.first;
      i++;
      v.second = i;
    }
  }
  sort(a.begin(), a.end(), greater<>());

  for (const auto& v : a) {
    cout << v.second << endl;
  }
  return 0;
}
