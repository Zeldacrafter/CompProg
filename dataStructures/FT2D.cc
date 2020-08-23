#include "../template.cc"
struct FT2D {
  struct FT {
    using T = int;
    vector<T> A;
    int n;
    FT(int n) : A(n + 1, 0), n(n) {}
    int inline LSOne(int i) { return i & (-i); }
    T query(int i) {
      T sum = 0;
      for (; i; i -= LSOne(i)) sum += A[i];
      return sum;
    }
    T query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int add) {
      for (; i <= n; i += LSOne(i)) A[i] += add;
    }
  };
  using T = FT::T;
  vector<FT> fts;
  int n;
  FT2D(int n, int m) : fts(n + 1, FT(m)), n(n) {};
  int inline LSOne(int i) { return i & (-i); }
  T query(int i, int j1, int j2) {
    T sum = 0;
    for (; i; i -= LSOne(i)) sum += fts[i].query(j1, j2);
    return sum;
  }
  T query(int i1, int i2, int j1, int j2) {
    return query(i2, j1, j2) - query(i1 - 1, j1, j2);
  }
  void update(int i, int j, T add) {
    for (; i <= n; i += LSOne(i)) fts[i].update(j, add);
  }
};
