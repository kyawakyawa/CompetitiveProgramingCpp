#include <assert.h>

#include <algorithm>
#include <vector>

using namespace std;

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

template <typename T>
struct UnionOfRectangle2D {
  CoordinateCompress<T> x, y;
  vector<T> x1, y1, x2, y2;
  int64_t n = 0;

  // Note
  // [x1,x2],  [y1, y2]

  UnionOfRectangle2D() = default;
  UnionOfRectangle2D(const vector<T>& x1_, const vector<T>& y1_,
                     const vector<T>& x2_, const vector<T>& y2_) {
    Init(x1_, y1_, x2_, y2_);
  }

  void Init(const vector<T>& x1_, const vector<T>& y1_, const vector<T>& x2_,
            const vector<T>& y2_) {
    Add(x1_, y1_, x2_, y2_);
  }

  void Add(const vector<T>& x1_, const vector<T>& y1_, const vector<T>& x2_,
           const vector<T>& y2_) {
    assert(x1_.size() == y1_.size());
    assert(y1_.size() == x2_.size());
    assert(x2_.size() == y2_.size());

    int64_t dn = int64_t(x1_.size());

    x1.reserve(dn + n);
    y1.reserve(dn + n);
    x2.reserve(dn + n);
    y2.reserve(dn + n);

    copy(x1_.begin(), x1_.end(), back_inserter(x1));
    copy(y1_.begin(), y1_.end(), back_inserter(y1));
    copy(x2_.begin(), x2_.end(), back_inserter(x2));
    copy(y2_.begin(), y2_.end(), back_inserter(y2));

    x.Add(x1_);
    x.Add(x2_);
    y.Add(y1_);
    y.Add(y2_);

    n += dn;
  }

  void Build(void) {
    x.Build();
    y.Build();
  }

  T GetArea() const {
    int64_t my = int64_t(y.xs.size());
    int64_t mx = int64_t(x.xs.size());

    vector<vector<int64_t>> c(my, vector<int64_t>(mx, 0));
    vector<int64_t> sx = x.GetId(x1);
    vector<int64_t> sy = y.GetId(y1);
    vector<int64_t> tx = x.GetId(x2);
    vector<int64_t> ty = y.GetId(y2);

    // 2D Imos
    for (int64_t i = 0; i < n; ++i) {
      c[sy[i]][sx[i]]++;
      c[sy[i]][tx[i]]--;
      c[ty[i]][sx[i]]--;
      c[ty[i]][tx[i]]++;
    }

    for (int64_t i = 0; i < my; ++i) {
      for (int64_t j = 0; j < mx - 1; ++j) {
        c[i][j + 1] += c[i][j];
      }
    }

    for (int64_t i = 0; i < my - 1; ++i) {
      for (int64_t j = 0; j < mx; ++j) {
        c[i + 1][j] += c[i][j];
      }
    }

    int64_t ret = 0;
    for (int64_t i = 0; i < my - 1; ++i) {
      for (int64_t j = 0; j < mx - 1; ++j) {
        if (c[i][j] > 0) {
          ret += (y.xs[i + 1] - y.xs[i]) * (x.xs[j + 1] - x.xs[j]);
        }
      }
    }

    return ret;
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

#include <iostream>

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_4_A

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t N;
  cin >> N;

  vector<int64_t> x1(N), y1(N), x2(N), y2(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  UnionOfRectangle2D<int64_t> ur(x1, y1, x2, y2);
  ur.Build();

  cout << ur.GetArea() << endl;

  return EXIT_SUCCESS;
}
