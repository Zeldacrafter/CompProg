#include "FT.cc"
template<typename T>
struct FT2D {
  int n;
  vector<FT<T>> fts;
  FT2D(int sz1, int sz2) : n{sz1}, fts(n + 1, FT<T>(sz2)) {};
  T query(int i, int j1, int j2) {
    T sum = 0;
    for (--i; i >= 0; i = (i & (i + 1)) - 1) sum += fts[i].query(j1, j2);
    return sum;
  }
  T query(int i1, int i2, int j1, int j2) {
    return query(i2, j1, j2) - query(i1, j1, j2);
  }
  void update(int i, int j, T add) {
    for (; i < n; i |= i + 1) fts[i].update(j, add);
  }
};
