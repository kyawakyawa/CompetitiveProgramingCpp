#include <stdint.h>

#include <string>
#include <vector>

using namespace std;

template <uint64_t mod>
struct RollingHash {
  vector<uint64_t> hashed, power;

  RollingHash(const string& s, uint64_t base = 10007) {
    int64_t sz = int64_t(s.size());

    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for (int64_t i = 0; i < sz; ++i) {
      power[i + 1]  = (power[i] * base) % mod;
      hashed[i + 1] = (hashed[i] * base) % mod + s[i];
      hashed[i + 1] %= mod;
    }
  }

  // [l, r) のハッシュ値
  uint64_t Get(int64_t l, int64_t r) const {
    uint64_t ret = hashed[r] + mod - (hashed[l] * power[r - l]) % mod;
    if (ret >= mod) ret -= mod;
    return ret;
  }
};
