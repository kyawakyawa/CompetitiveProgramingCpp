#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using default_counter_t = int64_t;

// macro
#define let auto const&
#define overload4(a, b, c, d, name, ...) name
#define rep1(n) \
  for (default_counter_t i = 0, end_i = default_counter_t(n); i < end_i; ++i)
#define rep2(i, n)                                                           \
  for (default_counter_t i = 0, end_##i = default_counter_t(n); i < end_##i; \
       ++i)
#define rep3(i, a, b)                                    \
  for (default_counter_t i       = default_counter_t(a), \
                         end_##i = default_counter_t(b); \
       i < end_##i; ++i)
#define rep4(i, a, b, c)                                 \
  for (default_counter_t i       = default_counter_t(a), \
                         end_##i = default_counter_t(b); \
       i < end_##i; i += default_counter_t(c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(n) \
  for (default_counter_t i = default_counter_t(n) - 1; i >= 0; --i)
#define rrep2(i, n) \
  for (default_counter_t i = default_counter_t(n) - 1; i >= 0; --i)
#define rrep3(i, a, b)                                         \
  for (default_counter_t i         = default_counter_t(b) - 1, \
                         begin_##i = default_counter_t(a);     \
       i >= begin_##i; --i)
#define rrep4(i, a, b, c)                                          \
  for (default_counter_t                                           \
           i = (default_counter_t(b) - default_counter_t(a) - 1) / \
                   default_counter_t(c) * default_counter_t(c) +   \
               default_counter_t(a),                               \
           begin_##i = default_counter_t(a);                       \
       i >= begin_##i; i -= default_counter_t(c))
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
  In(rest...);
  return;
}

template <class T, typename I>
void VectorIn(vector<T>& v, const I n) {
  v.resize(size_t(n));
  rep(i, v.size()) cin >> v[i];
}

void Out(void) {
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void Out(First first, Rest... rest) {
  cout << first << " ";
  Out(rest...);
  return;
}

constexpr auto yes(const bool c) { return c ? "yes" : "no"; }
constexpr auto Yes(const bool c) { return c ? "Yes" : "No"; }
constexpr auto YES(const bool c) { return c ? "YES" : "NO"; }

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

bool Solve(string& a, string& b, int64_t depth) {
  if (depth == 3) {
    return a == b;
  }

  bool ret = false;
  rep(i, b.size()) {
    rep(j, i + 1, b.size()) {
      string b_ = b;
      swap(b_[i], b_[j]);
      ret |= (Solve(a, b_, depth + 1));
    }
  }
  return ret;
}

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  string A, B;
  In(A, B);

  int64_t n = int64_t(A.size());

  vector<int64_t> cnt_a(26, 0);
  vector<int64_t> cnt_b(26, 0);

  rep(i, n) {
    cnt_a[A[i] - 'a']++;
    cnt_b[B[i] - 'a']++;
  }

  bool flag = true;
  rep(i, 26) {
    if (cnt_a[i] != cnt_b[i]) {
      flag = false;
    }
  }

  if (!flag) {
    cout << "NO" << endl;
    return EXIT_SUCCESS;
  }

  flag = false;
  rep(i, 26) {
    if (cnt_a[i] > 1) {
      flag = true;
      break;
    }
  }

  int64_t cnt = 0;
  string a, b;
  rep(i, n) {
    if (A[i] != B[i]) {
      cnt++;
      a.push_back(A[i]);
      b.push_back(B[i]);
    }
  }

  int64_t flag_ = false;

  flag_ |= (flag && cnt < 5);
  flag_ |= (cnt == 2);

  if (cnt <= 6) {
    flag_ |= Solve(a, b, 0);
  }

  cout << YES(flag_) << endl;

  return EXIT_SUCCESS;
}
