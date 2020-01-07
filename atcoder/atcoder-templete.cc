#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

// macro
#define let auto const&
#define overload4(a, b, c, d, name, ...) name
#define rep1(n) for (int i = 0, end_i = (n); i < end_i; ++i)
#define rep2(i, n) for (int i = 0, end_##i = (n); i < end_##i; ++i)
#define rep3(i, a, b) for (int i = (a), end_##i = (b); i < end_##i; ++i)
#define rep4(i, a, b, c) for (int i = (a), end_##i; i < end_##i; i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (int i = (n)-1; i >= 0; --i)
#define rrep2(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep3(i, a, b) for (int i = (b)-1, begin_##i = (a); i >= begin_##i; --i)
#define rrep4(i, a, b, c)                                        \
  for (int i = ((b) - (a)-1) / (c) * (c) + (a), begin_##i = (a); \
       i >= begin_##i; i -= c)
#define rrep(...) \
  overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define ALL(f, c, ...)                                           \
  (([&](decltype((c)) cccc) {                                    \
    return (f)(std::begin(cccc), std::end(cccc), ##__VA_ARGS__); \
  })(c))

// function
template <class C>
constexpr C& Sort(C& a) {
  std::sort(std::begin(a), std::end(a));
  return a;
}
template <class C>
constexpr auto& Min(C const& a) {
  return *std::min_element(std::begin(a), std::end(a));
}
template <class C>
constexpr auto& Max(C const& a) {
  return *std::max_element(std::begin(a), std::end(a));
}
template <class C>
constexpr auto Total(C const& c) {
  return std::accumulate(std::begin(c), std::end(c), C(0));
}
template <typename T>
auto CumSum(std::vector<T> const& v) {
  std::vector<T> a(v.size() + 1, T(0));
  for (std::size_t i = 0; i < a.size() - size_t(1); ++i) a[i + 1] = a[i] + v[i];
  return a;
}
template <typename T>
constexpr bool ChMax(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
constexpr bool ChMin(T& a, T const& b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

void In(void) { return; }

template <typename First, typename... Rest>
void In(First& first, Rest&... rest) {
  cin >> first;
  IN(rest...);
  return;
}

void Out(void) {
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void Out(First first, Rest... rest) {
  cout << first << " ";
  OUT(rest...);
  return;
}

constexpr auto yes(bool const& c) { return c ? "yes" : "no"; }
constexpr auto Yes(bool const& c) { return c ? "Yes" : "No"; }
constexpr auto YES(bool const& c) { return c ? "YES" : "NO"; }

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
