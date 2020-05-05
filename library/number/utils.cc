#include <stdint.h>

#include <algorithm>
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

template <typename T>
vector<T> Divisor(const T n) {
  vector<T> ret;
  for (int64_t i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.emplace_back(i);
      if (i * i != n) ret.emplace_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

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
