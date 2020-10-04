#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string S;
  cin >> S;

  int cnt[] = {0, 0, 0, 0, 0, 0};

  for (const auto c : S) {
    ++cnt[c - 'A'];
  }

  for (int i = 0; i < 6; ++i) {
    printf("%d", cnt[i]);
    if (i < 5) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}
