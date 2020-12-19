#include "../template.cc"
// alphabets like 10^9 possible but for 200'000 values ~200MB
// for smaller alphabets consider the non pointer based variant
template<typename T = int>
struct WLT {
  using vit = typename vector<T>::iterator;
  struct node : vi {
    int l = -1, r = -1;
  };
  T H;
  vector<node> M;
  static inline T mid(T a, T b) { return (a + b + 1) / 2; }
  WLT(vector<T> v, T hi) : H{hi} { // [0, hi)
    M.reserve(SZ(v) * log2(H));
    build(ALL(v), 0, H);
  }
  int build(vit b, vit e, T lo, T hi) {
    int idx = SZ(M);
    M.eb();
    if (lo + 1 == hi) return idx;
    int m = mid(lo, hi);
    M[idx].reserve(distance(b, e) + 1); M[idx].pb(0);
    auto less = [=](T k) { return k < m; };
    for (auto it = b; it != e; ++it) M[idx].pb(M[idx].back() + less(*it));
    auto p = stable_partition(b, e, less);
    if (p != b) M[idx].l = build(b, p, lo, m); 
    if (p != e) M[idx].r = build(p, e, m, hi);
    return idx;
  }
  T kthsmallest(int l, int r, int k) {// k-th smallest in [l, r)
    T a = 0, b = H; int i = 0;
    while (a + 1 != b) {
      if (k < M[i][r] - M[i][l]) {
        l = M[i][l]; r = M[i][r];
        i = M[i].l; b = mid(a, b);
      } else {
        k -= M[i][r] - M[i][l];
        l -= M[i][l]; r -= M[i][r];
        i = M[i].r; a = mid(a, b);
      }
    }
    return a;
  }
};
