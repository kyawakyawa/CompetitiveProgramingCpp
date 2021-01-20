#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string Name;
  cin >> Name;
  string Eman = Name;
  reverse(Eman.begin(), Eman.end());
  if (Name == Eman) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
