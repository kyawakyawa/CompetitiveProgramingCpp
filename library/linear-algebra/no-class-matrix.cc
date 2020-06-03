#include <stdint.h>

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
using Mat = vector<vector<T>>;

template <typename T>
Mat<T> MakeMat(const int64_t m, const int64_t n, const T elm = T(0)) {
  return Mat<T>(m, vector<T>(n, elm));
}

template <typename T>
Mat<T> MakeIdentityMat(const int64_t m, const int64_t n) {
  Mat<T> ret = Mat<T>(m, vector<T>(n));
  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; ++j) {
      ret[i][j] = T(i == j);
    }
  }
  return ret;
}

template <typename T>
Mat<T> MatAdd(const Mat<T>& A, const Mat<T>& B) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());
  if (m != int64_t(B.size()) || n != int64_t(B[0].size())) {
    cerr << "add error" << endl;
    return MakeMat<T>(1, 1);
  }

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; j++) {
      ret[i][j] = A[i][j] + B[i][j];
    }
  }
}

template <typename T>
Mat<T> MatSub(const Mat<T>& A, const Mat<T>& B) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());
  if (m != int64_t(B.size()) || n != int64_t(B[0].size())) {
    cerr << "sub error" << endl;
    return MakeMat<T>(1, 1);
  }

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; j++) {
      ret[i][j] = A[i][j] - B[i][j];
    }
  }
}

template <typename T>
Mat<T> MatMul(const Mat<T>& A, const Mat<T>& B) {
  const int64_t m = int64_t(A.size());
  const int64_t l = int64_t(A[0].size());
  const int64_t n = int64_t(B[0].size());

  if (l != int64_t(B.size())) {
    cerr << "mul error" << endl;
    return MakeMat<T>(1, 1);
  }

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; ++j) {
      for (int64_t k = 0; k < l; ++k) {
        ret[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return ret;
}

template <typename T>
Mat<T> ScalarMulMat(const T a, const Mat<T>& A) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());

  Mat<T> ret = MakeMat(m, n, T(0));

  for (int64_t i = 0; i < m; ++i) {
    for (int64_t j = 0; j < n; ++j) {
      ret[i][j] = a * A[i][j];
    }
  }

  return ret;
}

template <typename T>
Mat<T> MatPow(const Mat<T> A, int64_t x) {
  const int64_t m = int64_t(A.size());
  const int64_t n = int64_t(A[0].size());

  Mat<T> ret = MakeIdentityMat<T>(m, n);
  Mat<T> tmp = A;
  while (x > 0) {
    if (x & 1) {
      ret = MatMul(ret, tmp);
    }
    tmp = MatMul(tmp, tmp);
    x /= 2;
  }
  return ret;
}
