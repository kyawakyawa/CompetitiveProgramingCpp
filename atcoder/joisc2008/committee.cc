#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tr;
vector<int> a;
vector<int> y;

int Dfs(int v) {
  int cnt = a[v];

  for (auto u : tr[v]) {
    int tmp = Dfs(u);
    if (tmp >= 0) {
      cnt += tmp;
    }
  }

  return y[v] = cnt;
}

int main(void) {
  cin >> n;
  tr.resize(n);
  a.resize(n);
  y.resize(n);

  int par = -1;
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s >> a[i];
    s--;
    if (s >= 0) {
      tr[s].emplace_back(i);
    } else {
      par = i;
    }
  }
  Dfs(par);
  cout << *max_element(y.begin(), y.end()) << endl;
  return 0;
}
