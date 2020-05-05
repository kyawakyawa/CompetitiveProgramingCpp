#include <vector>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
  vector<T> data;  // 1-indexed

  BinaryIndexedTree(size_t size) { data.assign(size + 1, 0); }

  T Sum(size_t k) {  // 0-indexed
    T ret = T(0);
    for (++k; k > 0; k -= (k & (-k))) {
      ret += data[k];
    }
    return ret;
  }

  void Add(size_t k, const T x) {  // 0-indexed
    for (++k; k < data.size(); k += (k & -k)) data[k] += x;
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
