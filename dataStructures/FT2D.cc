#include "FT.cc"
template<typename T>
struct FT2D {
  vector<FT<T>> fts;
  int n;
  FT2D(int n, int m) : fts(n + 1, FT<T>(m)), n(n) {};
  T query(int i, int j1, int j2) {
    T sum = 0;
    for (; i; i -= i & -i) sum += fts[i].query(j1, j2);
    return sum;
  }
  T query(int i1, int i2, int j1, int j2) {
    return query(i2, j1, j2) - query(i1 - 1, j1, j2);
  }
  void update(int i, int j, T add) {
    for (; i <= n; i += i & -i) fts[i].update(j, add);
  }
};
