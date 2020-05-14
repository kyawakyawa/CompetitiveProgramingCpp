#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct RAQ {
  int64_t n;
  int64_t k;  //バケットの数
  T sqrt_n;   //バケットの大きさ
  vector<T> data;
  vector<T> bucket_sum;

  RAQ() = delete;
  RAQ(const int64_t n_, const int64_t sqrt_n_ = 1000) {
    Initialize(n_, sqrt_n_);
  }

  void Initialize(const int64_t n_, const int64_t sqrt_n_ = 1000) {
    n = n_;

    sqrt_n = sqrt_n_;

    k = (n + sqrt_n - 1) / sqrt_n;  //切り上げ割り算

    data.clear();
    bucket_sum.clear();

    data.resize(k * sqrt_n, 0);
    bucket_sum.resize(k, 0);
  }

  void Add(const int64_t a, const int64_t b,
           const T x) {  //[a,b)(0-indexed)にx を加算
    if (a >= sqrt_n * k || b > sqrt_n * k) {
      cerr << "error index k" << endl;
      return;
    }
    if (a >= n || b > n) {
      cerr << "warning index k" << endl;
    }

    for (int64_t i = 0; i < k; ++i) {
      int64_t l = i * sqrt_n, r = (i + 1) * sqrt_n;
      if (b <= l || r <= a) continue;
      if (l < a || b < r) {
        for (int64_t j = max(l, a); j < min(b, r); ++j) {
          data[j] += x;
        }
      } else {
        bucket_sum[i] += x;
      }
    }
  }

  T Get(const int64_t i) {  // i番目(0-indexed)の値を取得する
    return data[i] + bucket_sum[i / sqrt_n];
  }
};
