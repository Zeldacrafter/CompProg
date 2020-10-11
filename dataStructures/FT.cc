#include "../template.cc"
template<typename T>
struct FT {
  vector<T> A;
  int n;
  FT(int _n) : A(_n + 1, 0), n(_n) {}
  T query(int i) {
    T sum = 0;
    for (; i; i -= i & -i) sum += A[i];
    return sum;
  }
  T query(int i, int j) { return query(j) - query(i - 1); }
  void update(int i, T add) {
    for (; i <= n; i += i & -i) A[i] += add;
  }
  // lb assumes query(i, i) >= 0 forall i in [1, n]
  // returns min p >= 1, so that [1, p] >= sum
  // if [1, n] < sum, return n + 1
  int lb(T sum) {
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= n && sum > A[pos | pw]) sum -= A[pos |= pw];
    return pos + !!sum;
  }
};
