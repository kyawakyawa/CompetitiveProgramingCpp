#include <vector>

using namespace std;

template <typename T>
struct UnionFind {
  vector<T> par;    //親の番号
  vector<T> urank;  //集合のランク
  vector<T> usize;  //集合の要素数
  T num;            //集合の数

  UnionFind() { Init(100000); }

  UnionFind(const T n) { Init(n); }

  void Init(const T n) {  // 0〜n-1までの要素を初期化 最初はバラバラ
    par.clear();
    urank.clear();
    usize.clear();
    par.resize(n);
    urank.resize(n);
    usize.resize(n);
    num = n;
    for (T i = 0; i < n; ++i) {
      par[i]   = i;
      urank[i] = T(0);
      usize[i] = T(1);
    }
  }

  T Find(T x) {  // xが属する集合の親を見つける
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = Find(par[x]);
    }
  }

  T GetSetSize(T x) {  // xが属する集合の要素数を返す。
    return usize[Find(x)];
  }

  void Unite(T x, T y) {  // xが属する集合とyが属する集合を併合する。
    x = Find(x);
    y = Find(y);
    if (x == y) return;

    T s = usize[x] + usize[y];
    num--;
    if (urank[x] < urank[y]) {
      par[x]   = y;
      usize[y] = s;
    } else {
      par[y]   = x;
      usize[x] = s;
      if (urank[x] == urank[y]) urank[x]++;
    }
  }

  bool Same(T x, T y) {  //同じ集合に属するかを判定する
    return Find(x) == Find(y);
  }

  T NumSet() {  //集合の数(木の数)を返す。
    return num;
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
