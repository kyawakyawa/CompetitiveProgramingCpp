#include <stdint.h>

#include <vector>
using namespace std;

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

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  return EXIT_SUCCESS;
}
