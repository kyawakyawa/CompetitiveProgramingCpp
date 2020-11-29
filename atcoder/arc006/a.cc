#include <stdio.h>

int main(void) {
  int E[7], L[7];
  int B;
  for (int i = 0; i < 6; ++i) {
    scanf("%d", E + i);
  }
  scanf("%d", &B);
  for (int i = 0; i < 6; ++i) {
    scanf("%d", L + i);
  }
  int cnts[10];
  for (int i = 0; i < 10; ++i) {
    cnts[i] = 0;
  }
  for (int i = 0; i < 6; ++i) {
    cnts[E[i]]++;
    cnts[L[i]]++;
  }
  int cnt = 0;
  for (int i = 0; i < 10; ++i) {
    if (cnts[i] == 2) {
      cnt++;
    }
  }
  if (cnt < 3) {
    printf("0\n");
  } else if (cnt == 6) {
    printf("1\n");
  } else if (cnt == 5) {
    bool flag = false;
    for (int i = 0; i < 6; ++i) {
      if (B == L[i]) {
        flag = true;
      }
    }
    if (flag) {
      printf("2\n");
    } else {
      printf("3\n");
    }
  } else {
    printf("%d\n", 8 - cnt);
  }
  return 0;
}
