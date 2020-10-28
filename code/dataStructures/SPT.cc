#include "../template.hh"
template <typename T, typename F>
struct SPT {
  vector<vector<T>> d;
  F f;
  SPT (int n, F _f) : d(32 - __builtin_clz(n), vector<T>(n)), f{_f} {}
  SPT (const vector<T>& v, F _f) : SPT(SZ(v), _f) {
    d[0] = v;
    build();
  }
  void build() {
    for (int j = 1; (1 << j) <= SZ(d[0]); ++j) {
      for (int i = 0; i + (1 << j) <= SZ(d[0]); ++i) {
        d[j][i] = f(d[j - 1][i], d[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) { // [l, r)
    int k = 31 - __builtin_clz(r - l);
    return f(d[k][l], d[k][r - (1 << k)]);
  }
};

