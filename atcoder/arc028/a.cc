#include <iostream>

using namespace std;

int main(void) {
  int N, A, B;
  cin >> N >> A >> B;
  while (true) {
    N -= A;
    if (N <= 0) {
      printf("Ant\n");
      break;
    }
    N -= B;
    if (N <= 0) {
      printf("Bug\n");
      break;
    }
  }
  return 0;
}
