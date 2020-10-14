#include "../template.cc"
// only suitable for relatively small alphabets ~10^6
template<typename T = int>
struct WLT {
  using vt = typename vector<T>::iterator;
  T H;
  vvi M;
  static inline T mid(T a, T b) { return (a + b + 1) / 2; }
  static inline int left(int i) { return i << 1; }
  static inline int right(int i) { return i << 1 | 1; }
  // [0, hi)
  WLT(vector<T> v, T hi) : H{hi}, M(H) {
    build(ALL(v), 1, 0, H);
  }
  void build(vt b, vt e, int i, T lo, T hi) {
    if (lo + 1 == hi) return;
    int m = mid(lo, hi);
    M[i].reserve(distance(b, e) + 1); M[i].pb(0);
    auto less = [=](T k) { return k < m; };
    for (auto it = b; it != e; ++it) M[i].pb(M[i].back() + less(*it));
    auto p = stable_partition(b, e, less);
    if (p != b) build(b, p, left(i), lo, m); 
    if (p != e) build(p, e, right(i), m, hi);
  }
  // k-th smallest in [l, r)
  T kthsmallest(int l, int r, int k) {
    T lo = 0, hi = H; int i = 1;
    while (lo + 1 != hi) {
      if (k < M[i][r] - M[i][l]) {
        l = M[i][l]; r = M[i][r];
        i = left(i); hi = mid(lo, hi);
      } else {
        k -= M[i][r] - M[i][l];
        l -= M[i][l]; r -= M[i][r];
        i = right(i); lo = mid(lo, hi);
      }
    }
    return lo;
  }
};
