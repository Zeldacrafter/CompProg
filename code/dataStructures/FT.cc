#include "../template.hh"
template<typename T>
struct FT {
  int n;
  vector<T> A;
  FT(int sz) : n{sz}, A(n, 0) {}
  T query(int i) {
    T sum = 0;
    for (--i; i >= 0; i = (i & (i + 1)) - 1) sum += A[i];
    return sum;
  }
  T query(int i, int j) { return query(j) - query(i); }
  void update(int i, T add) {
    for (; i < n; i |= i + 1) A[i] += add;
  }
  // lb assumes query(i, i) >= 0 forall i in [1, n]
  // returns min p >= 1, so that [1, p] >= sum
  // if [1, n] < sum, return n + 1
  /* TODO: 0 indexed
  int lb(T sum) {
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= n && sum > A[pos | pw]) sum -= A[pos |= pw];
    return pos + !!sum;
  }
  */
};
