#include <stdint.h>

#include <bitset>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int64_t N;
  cin >> N;

  vector<string> ans;
  ans.reserve(1000000);
  for (int64_t i = 0; i < (1 << N); ++i) {
    bitset<20> bs = i;
    string s = "";
    int64_t l = 0;
    bool flag = true;
    for (int64_t j = 0; j < N; ++j) {
      if (bs[j]) {
        l++;
      } else {
        l--;
      }
      if (l < 0) {
        flag = false;
      }
      s.push_back(bs[j] ? '(' : ')');
    }
    if (l == 0 && flag) {
      ans.emplace_back(s);
    }
  }
  sort(ans.begin(),ans.end());
  for (const auto& s : ans) {
    cout << s << endl;
  }

  return 0;
}
