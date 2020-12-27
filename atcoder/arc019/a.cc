#include <iostream>
#include <map>

using namespace std;

int main(void) {
  std::map<char, int> replace;

  replace.emplace('O', 0);
  replace.emplace('D', 0);
  replace.emplace('I', 1);
  replace.emplace('Z', 2);
  replace.emplace('S', 5);
  replace.emplace('B', 8);

  string S;
  cin >> S;
  for (auto& c : S) {
    if (replace.count(c)) {
      c = char(replace.at(c)) + '0';
    }
  }
  cout << S << endl;

  return 0;
}
