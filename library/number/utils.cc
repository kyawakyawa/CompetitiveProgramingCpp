#include <stdint.h>
#include <map>
#include <vector>
using namespace std;

template <typename T>
T Gcd(const T a, const T b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}

template <typename T>
map<T, T> PrimeFactor(T n) {
  map<T, T> ret;
  for (int64_t i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}