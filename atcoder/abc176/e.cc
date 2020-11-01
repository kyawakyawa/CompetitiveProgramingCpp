#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
  int H, W, M;
  cin >> H >> W >> M;
  vector<int> h(M), w(M);
  for (int i = 0; i < M; ++i) {
    cin >> h[i] >> w[i];
    h[i]--;
    w[i]--;
  }

  map<int, int> cnt_r;
  for (int i = 0; i < M; ++i) {
    cnt_r[h[i]]++;
  }
  map<int, int> cnt_c;
  for (int i = 0; i < M; ++i) {
    cnt_c[w[i]]++;
  }
  int mx_r = 0;
  for (const auto& v : cnt_r) {
    mx_r = max(mx_r, v.second);
  }
  vector<int> mx_r_i;
  for (auto& v : cnt_r) {
    if (v.second == mx_r) {
      mx_r_i.emplace_back(v.first);
    }
  }

  int mx_c = 0;
  for (const auto& v : cnt_c) {
    mx_c = max(mx_c, v.second);
  }
  vector<int> mx_c_i;
  for (auto& v : cnt_c) {
    if (v.second == mx_c) {
      mx_c_i.emplace_back(v.first);
    }
  }

  if (mx_r_i.size() * mx_c_i.size() > size_t(M)) {
    cout << mx_r + mx_c << endl;
    return EXIT_SUCCESS;
  }

  using P = pair<int, int>;
  map<P, int> cnt_rc;
  for (int i = 0; i < M; ++i) {
    cnt_rc[P(h[i], w[i])]++;
  }

  for (const int i : mx_r_i) {
    for (const int j : mx_c_i) {
      if (cnt_rc[P(i, j)] == 0) {
        cout << mx_r + mx_c << endl;
        return EXIT_SUCCESS;
      }
    }
  }

  cout << mx_r + mx_c - 1 << endl;

  return 0;
}
