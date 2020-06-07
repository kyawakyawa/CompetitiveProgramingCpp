#include <stdint.h>

#include <functional>
#include <vector>

using namespace std;

template <typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;

  int64_t sz;
  vector<Monoid> seg;

  const F f;
  const Monoid e;

  SegmentTree(const int64_t n, const F f_, const Monoid &e_) : f(f_), e(e_) {
    sz = 1;
    while (sz < n) sz <<= int64_t(1);
    seg.assign(2 * sz, e);
  }

  void Set(const int64_t k, const Monoid &x) { seg[k + sz] = x; }

  void Build() {
    // Note: Root is seg[1]. seg[0] is not used.
    for (int64_t k = sz - 1; k > 0; --k) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  // Note k -> 0-indexedededed
  //      k in [0, sz)
  void Update(int64_t k, const Monoid &x) {
    // TODO: out of range error
    k += sz;
    seg[k] = x;
    while (k >>= int64_t(1)) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

#if 1
  // Note a, b -> 0-indexed
  //      a < b
  //      0 <= a < sz
  //      1 <= b <= sz
  //      sum in [a, b)
  Monoid Query(int64_t a, int64_t b) {
    Monoid L = e, R = e;
    // TODO: out of range error
    for (a += sz, b += sz; a < b; a >>= int64_t(1), b >>= int64_t(1)) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
#else
  Monoid Query(const int64_t a, const int64_t b, const int64_t k = 1,
               const int64_t l = 0, int64_t r = 0) {
    if (l >= r) r = sz;
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return seg[k];

    int64_t vl = Query(a, b, 2 * k, l, (l + r) / 2);
    int64_t vr = Query(a, b, 2 * k + 1, (l + r) / 2, r);

    return f(vl, vr);
  }
#endif

  Monoid operator[](const int64_t &k) const { return seg[k + sz]; }
};

#include <iostream>

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A

signed main(int argc, char *argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t N, Q;

  cin >> N >> Q;

  const int64_t kInf = (int64_t(1) << int64_t(31)) - 1;
  SegmentTree<int64_t> seg_tree(
      N, [](int64_t a, int64_t b) { return min(a, b); }, kInf);

  while (Q--) {
    int64_t com, x, y;
    cin >> com >> x >> y;
    if (com == 0)
      seg_tree.Update(x, y);
    else
      cout << seg_tree.Query(x, y + 1) << endl;
  }
  return EXIT_SUCCESS;
}
