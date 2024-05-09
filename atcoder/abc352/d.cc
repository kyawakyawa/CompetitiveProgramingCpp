#include <functional>
#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

ll N;
ll K;
ll P[300000];
ll Q[300000];

int main(void) {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    cin >> P[i];
    Q[P[i] - 1] = i;
  }

  set<ll> S;
  for (ll i = 0; i < K; ++i) {
    S.insert(Q[i]);
  }
  ll ans = N - 1;
  for (ll i = 0; i < N; ++i) {
    if (i + K - 1 >= N) {
      break;
    }

    S.insert(Q[i + K - 1]);

    if (*S.rbegin() - *S.begin() < ans) {
      ans = *S.rbegin() - *S.begin();
    }
    S.erase(Q[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
