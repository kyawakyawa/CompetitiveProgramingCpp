#include <iostream>
#include <string>

using namespace std;

int cnt[256];

int main(void) {
  std::string w;
  cin >> w;

  for (const auto c : w) {
    cnt[int(c)]++;
  }

  bool flag = true;
  for (int i = 0; i < 256; ++i) {
    if (cnt[i] % 2) flag = false;
  }
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
