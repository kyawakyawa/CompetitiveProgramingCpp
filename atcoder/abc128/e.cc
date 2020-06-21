#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <tuple>
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

// http://koturn.hatenablog.com/entry/2018/08/01/010000
template <typename T, typename U>
inline std::vector<U> MakeNdVector(T n, U val) noexcept {
  static_assert(std::is_integral<T>::value,
                "[MakeNdVector] The 1st argument must be an integer");
  return std::vector<U>(std::forward<T>(n), std::forward<U>(val));
}

template <typename T, typename... Args>
inline decltype(auto) MakeNdVector(T n, Args&&... args) noexcept {
  static_assert(std::is_integral<T>::value,
                "[MakeNdVector] The 1st argument must be an integer");
  return std::vector<decltype(MakeNdVector(std::forward<Args>(args)...))>(
      std::forward<T>(n), MakeNdVector(std::forward<Args>(args)...));
}

template <typename T, std::size_t N,
          typename std::enable_if<(N > 0), std::nullptr_t>::type = nullptr>
struct NdvectorImpl {
  using type = std::vector<typename NdvectorImpl<T, N - 1>::type>;
};  // struct ndvector_impl

template <typename T>
struct NdvectorImpl<T, 1> {
  using type = std::vector<T>;
};  // struct ndvector_impl

template <typename T, std::size_t N>
using NdVector = typename NdvectorImpl<T, N>::type;

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

template <typename T>
struct CoordinateCompress {
  vector<T> xs;

  CoordinateCompress() = default;
  CoordinateCompress(const vector<int64_t>& vs) { Add(vs); }
  CoordinateCompress(const initializer_list<vector<T>>& vs) {
    for (auto& v : vs) {
      Add(v);
    }
  }

  void Add(const vector<T>& vs) {
    size_t dn = vs.size();
    xs.reserve(xs.size() + dn);

    copy(vs.begin(), vs.end(), back_inserter(xs));
  }

  void Add(const T& x) { xs.emplace_back(x); }

  void Build(void) {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
  }

  vector<int64_t> GetId(const vector<T>& vs) const {
    vector<int64_t> ret;
    ret.reserve(vs.size());
    transform(vs.begin(), vs.end(), back_inserter(ret), [&](const T& x) {
      return lower_bound(xs.begin(), xs.end(), x) - begin(xs);
    });
    return ret;
  }

  int64_t GetId(const T& x) const {
    return lower_bound(xs.begin(), xs.end(), x) - begin(xs);
  }

  const T& operator[](const int64_t k) const { return xs[k]; }
};

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
#if 0
  int64_t N, Q;
  In(N, Q);
  vector<int64_t> S(N), T(N), X(N);
  rep(i, N) { In(S[i], T[i], X[i]); }
  vector<int64_t> D(Q);
  rep(i, Q) { In(D[i]); }

  {
    using Tl = tuple<int64_t, int64_t, int64_t>;
    vector<Tl> xst;
    rep(i, N) xst.emplace_back(X[i], S[i], T[i]);
    Sort(xst);
    rep(i, N) {
      X[i] = get<0>(xst[i]);
      S[i] = get<1>(xst[i]);
      T[i] = get<2>(xst[i]);
    }
  }

  CoordinateCompress<int64_t> cc(D);
  cc.Build();

  vector<int64_t> xs(Q, -1);

  set<int64_t> st;
  rep(i, Q) st.insert(i);

  rep(i, N) {
    int64_t s = S[i] - X[i];
    int64_t t = T[i] - X[i];

    int64_t si = cc.GetId(s);
    int64_t ti = cc.GetId(t);
    int64_t j  = si;
    while (true) {
      auto it = st.lower_bound(j);
      if (it == st.end() || *it >= ti) break;
      j = *it;
      st.erase(it);

      xs[j] = X[i];
    }
  }

  rep(i, Q) { cout << xs[i] << endl; }

#else

  using Type  = pair<int64_t, int64_t>;
  using Event = pair<int64_t, Type>;
  int64_t N, Q;
  cin >> N >> Q;
  vector<Event> v;

  for (int64_t i = 0; i < N; ++i) {
    int64_t s, t, x;
    cin >> s >> t >> x;
    v.emplace_back(s - x, Type(-1, x));
    v.emplace_back(t - x, Type(0, x));
  }

  for (int64_t i = 0; i < Q; ++i) {
    int64_t d;
    cin >> d;
    v.emplace_back(d, Type(1, i));
  }

  sort(v.begin(), v.end());

  vector<int64_t> ans(Q);
  multiset<int64_t> se;

  for (auto p : v) {
    int64_t type = p.second.first;
    int64_t val  = p.second.second;
    if (type == -1)
      se.insert(val);
    else if (type == 0)
      se.erase(se.lower_bound(val));
    else
      ans[val] = (se.empty() ? -1 : *(se.begin()));
  }
  for (auto a : ans) cout << a << endl;

#endif

  return EXIT_SUCCESS;
}
