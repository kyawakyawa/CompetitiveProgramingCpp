#include <functional>
#include <iostream>
using namespace std;

/*判定関数C(x) T→ bool ( x∈[s,t) )
  C(X) は　広義単調増加 つまり 0,0,0,...0,1,1,1,...1
  ただし C(x) ≡ 0 または C(x) ≡ 1 の場合もありうる

  この時C(x) = 1を満たす最小のｘを返す ただしtが帰ってきたらすべて 0 ということ
*/
// O(log(t - s))
//参考 https://qiita.com/hamko/items/794a92c456164dcc04ad

template <typename T>
bool C(T x) {
  (void)x;
  // 上の条件を満たす関数
  return false;
}

template <typename T>
T LowerBound(T s, T t, function<bool(T)> Comp = C<T>) {
  T lb = s - 1, ub = t;

  while (ub - lb > 1) {
    T mid = (ub + lb) / 2;  // ub lb がともに大きい時オーバフローするので注意

    (Comp(mid) ? ub : lb) = mid;
  }

  return ub;  // ub = t のときはすべてfalse
}

int main() {
  cout << LowerBound(1, 100) << endl;  // 100が変える
  return 0;
}
