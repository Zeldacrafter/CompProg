// TODO(Alex): Lazy updates, example for
// complex queries?
vi A;  // the array on which the range
       // queries are performed;
// segment tree for range maximum queries
class SegmentTree {
 private:
  vi value;
  int inline left(int p) { return p << 1; }
  int inline right(int p) {
    return (p << 1) + 1;
  }

  int build(int p, int L, int R) {
    if (L == R) {
      return value[p] = A[L];
    } else {
      value[p] =
          max(build(left(p), L, (R + L) / 2),
              build(right(p),
                    (R + L) / 2 + 1, R));
      return value[p];
    }
  }
  int rmq(int p, int L, int R, int i,
          int j) {
    if (i > R || j < L)
      return numeric_limits<int>::min();
    if (i <= L && R <= j) return value[p];
    return max(
        rmq(left(p), L, (L + R) / 2, i, j),
        rmq(right(p), (L + R) / 2 + 1, R, i,
            j));
  }

 public:
  SegmentTree() : value(SZ(A) * 4) {
    build(1, 0, SZ(A) - 1);
  }
  int rmq(int i, int j) {
    return rmq(1, 0, SZ(A) - 1, i, j);
  }
};
