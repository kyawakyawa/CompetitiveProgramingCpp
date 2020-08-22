#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <vector>

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

template <typename T>
struct Combination {
  vector<T> _fact, _rfact, _inv;

  Combination(int64_t sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for (int64_t i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for (int64_t i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for (int64_t i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T Fact(int64_t k) const { return _fact[k]; }

  inline T Rfact(int64_t k) const { return _rfact[k]; }

  inline T Inv(int64_t k) const { return _inv[k]; }

  T P(int64_t n, int64_t r) const {
    if (r < 0 || n < r) return 0;
    return Fact(n) * Rfact(n - r);
  }

  T C(int64_t p, int64_t q) const {
    if (q < 0 || p < q) return 0;
    return Fact(p) * Rfact(q) * Rfact(p - q);
  }

  T H(int64_t n, int64_t r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

using Mi = ModInt<1000000007>;

int main(void) {
  Combination<Mi> combi(1000000);

  int64_t X, Y;
  cin >> X >> Y;

  if (X < Y) {
    swap(X, Y);
  }

  int64_t Z = X - Y;

  for (int64_t k = 0; k <= 500000; ++k) {
    int64_t x = 2 * (Z + k) + k;
    int64_t y = 2 * k + (Z + k);

    if (x == X && y == Y) {
      int64_t n = Z + k + k;
      cout << combi.C(n, k) << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}
