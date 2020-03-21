#include "../template.cc"
// TODO(Alex): Lazy updates, example for
// complex queries?
// segment tree for range maximum queries
class SegmentTree {
 private:
  int n;
  vi value, up;
  int inline left(int p) { return p << 1; }
  int inline right(int p) {
    return (p << 1) + 1;
  }
  int build(const vi& a, int p, int L,
            int R) {
    if (L == R) {
      return value[p] = a[L];
    } else {
      value[p] = max(
          build(a, left(p), L, (R + L) / 2),
          build(a, right(p), (R + L) / 2 + 1,
                R));
      return value[p];
    }
  }
  int rmq(int p, int L, int R, int i,
          int j) {
    if (i > R || j < L)
      return numeric_limits<int>::min();
    if (i <= L && R <= j) return value[p];
    push(p, L, R);
    return max(
        rmq(left(p), L, (L + R) / 2, i, j),
        rmq(right(p), (L + R) / 2 + 1, R, i,
            j));
  }
  int add(int p, int L, int R, int i, int j,
          int val) {
    if (i > R || j < L) return value[p];
    if (L == R) return value[p] += val;
    if (i <= L && R <= j) {
      up[p] += val;
      return value[p] += val;
    }
    push(p, L, R);
    return value[p] = max(
               add(left(p), L, (L + R) / 2,
                   i, j, val),
               add(right(p), (L + R) / 2 + 1,
                   R, i, j, val));
  }
  void push(int p, int L, int R) {
    if (up[p]) {
      add(left(p), L, (L + R) / 2, L, R,
          up[p]);
      add(right(p), (L + R) / 2 + 1, R, L, R,
          up[p]);
      up[p] = 0;
    }
  }

 public:
  SegmentTree(int n)
      : n(n),
        value(n * 4, 0),
        up(n * 4, 0) {}
  SegmentTree(const vi& a)
      : n(SZ(a)),
        value(SZ(a) * 4),
        up(SZ(a) * 4) {
    build(a, 1, 0, SZ(a) - 1);
  }
  int rmq(int i, int j) {
    return rmq(1, 0, n - 1, i, j);
  }
  void add(int i, int j, int val) {
    add(1, 0, n - 1, i, j, val);
  }
  int size() { return n; }
};
