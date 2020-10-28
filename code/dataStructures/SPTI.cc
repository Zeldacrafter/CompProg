#include "../template.hh"
template <typename T, typename F> // F :: T -> T -> bool; first: true
struct SPTI { 
  vector<T> d;
  vvi idx;
  F f;
  SPTI (int n, F _f) : d(n), idx(32 - __builtin_clz(n), vi(n)), f{_f} {
    iota(ALL(idx[0]), 0);
  }
  SPTI (const vector<T>& v, F _f) : SPTI(SZ(v), _f) {
    d = v;
    build();
  }
  void build() {
    for (int j = 1; (1 << j) <= SZ(d); ++j) {
      for (int i = 0; i + (1 << j) <= SZ(d); ++i) {
        int k = i + (1 << (j - 1));
        idx[j][i] = f(d[idx[j - 1][i]], d[idx[j - 1][k]])
          ? idx[j - 1][i] : idx[j - 1][k];
      }
    }
  }
  int query(int l, int r) { // [l, r)
    int k = 31 - __builtin_clz(r - l);
    return f(d[idx[k][l]], d[idx[k][r - (1 << k)]])
      ? idx[k][l] : idx[k][r - (1 << k)];
  }
};
