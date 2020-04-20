#include "../template.cc"
class FenwickTree {
 private:
  vi A;
  int n;
  int inline LSOne(int i) { return i & (-i); }
  int query(int i) {
    int sum = 0;
    for (; i; i -= LSOne(i)) sum += A[i];
    return sum;
  }

 public:
  FenwickTree(int n) : A(n + 1, 0), n(n) {}
  void adjust(int i, int adjustBy) {
    for (; i <= n; i += LSOne(i)) A[i] += adjustBy;
  }
  int query(int i, int j) { return query(j) - query(i - 1); }
};
