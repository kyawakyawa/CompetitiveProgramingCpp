#include <stdint.h>

#include <algorithm>
#include <istream>
#include <ostream>

using namespace std;

template <int64_t Mod>
struct ModInt {
  int64_t x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {}

  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= Mod) x -= Mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if ((x += Mod - p.x) >= Mod) x -= Mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = int64_t(1LL * x * p.x % Mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.Inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt Inverse() const {
    int64_t a = x, b = Mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt Pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<Mod>(t);
    return (is);
  }

  static int64_t GetMod() { return Mod; }
};

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

signed main(int argc, char *argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  return EXIT_SUCCESS;
}
