#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> m;

int main(void) {
  string S;
  cin >> S;

  bool flag = false;

  if (S.size() == 1) {
    flag = S[0] == '8';
  } else if (S.size() == 2) {
    int a = int(S[0]) * 10 + int(S[1]) - int('0') - int('0');
    int b = int(S[1]) * 10 + int(S[0]) - int('0') - int('0');
    flag  = a % 8 == 0 || b % 8 == 0;
  } else {
    for (int i = 100; i < 1000; ++i) {
      if (i % 8 != 0) continue;
      vector<int> tmp;
      int k = i;
      for (int j = 0; j < 3; ++j) {
        tmp.emplace_back(k % 10);
        k /= 10;
      }
      if (tmp[0] != 0 && tmp[1] != 0 && tmp[2] != 0) {
        m.emplace_back(tmp);
      }
    }

    for (const auto c : S) {
      int k = c - '0';
      for (auto &v : m) {
        auto it = find(v.begin(), v.end(), k);
        if (it != v.end()) {
          v.erase(it);
        }
      }
    }

    for (auto &v : m) {
      if (v.empty()) {
        flag = true;
      }
    }
  }

  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
