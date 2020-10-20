#include <iostream>

using namespace std;

int pr[200000];
int rk[200000];
int sz[200000];

int find(int x) {
  if (pr[x] == x) return x;
  return pr[x] = find(pr[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rk[x] >= rk[y]) {
    pr[y] = x;
    sz[x] += sz[y];
    if (rk[x] == rk[y]) rk[x]++;
  } else {
    pr[x] = y;
    sz[y] += sz[x];
  }
}

int main(void) {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    pr[i] = i;
    rk[i] = 1;
    sz[i] = 1;
  }

  for (int i = 0; i < M; ++i) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;

    unite(A, B);
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, sz[i]);
  }
  cout << ans << endl;
  return 0;
}
