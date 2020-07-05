#include <string>
#include <vector>

using namespace std;

//
// 長さn の sが与えられた時
// i = 0,1,...,n-1 について
// s と s.substr(i) の最大共通接頭辞(先頭から何文字目までが等しいか)の個数を返す
// O(N)
//
// ex.
// aaabaaaab
// 921034210
//
vector<int64_t> ZAlgorithm(const string& s) {
  const int64_t n = int64_t(s.size());
  vector<int64_t> cnt(s.size());
  cnt[0]    = s.size();
  int64_t i = 1, j = 0;
  while (i < n) {
    while (i + j < n && s[j] == s[i + j]) ++j;
    cnt[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + cnt[k] < j) {
      cnt[i + k] = cnt[k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return cnt;
}
