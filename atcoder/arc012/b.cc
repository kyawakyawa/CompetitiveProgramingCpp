#include <stdio.h>

#include <iostream>

using namespace std;

int main(void) {
  int N;
  double va, vb;
  double L;
  cin >> N >> va >> vb >> L;

  for (int i = 0; i < N; ++i) {
    L = vb / va * L;
  }
  printf("%.10f\n", L);

  return 0;
}
