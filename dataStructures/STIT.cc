#include "../template.cc"
template<typename T>
struct ST {
  using type = T;
  using MT = function<T(const T&, const T&)>;
  const int n;
  const T unit;
  const MT merge;
  vector<T> data;
  ST(int sz, T u, MT m) : n{sz}, unit{u}, merge{m}, data(2 * n, unit) {}
  void build() {
    for (int i = n - 1; i; --i)
      data[i] = merge(data[i << 1], data[i << 1 | 1]);
  }
  T query(int l, int r) {
    T li = unit, ri = unit;
    for (l += n, r += n; l < r; r >>= 1, l >>= 1) {
      if (l & 1) li = merge(li, data[l++]);
      if (r & 1) ri = merge(data[--r], ri);
    }
    return merge(li, ri);
  }
  void update(int i, T val) {
    for (data[i += n] = val; i > 1; i >>= 1)
      data[i >> 1] = merge(data[i & ~1], data[i | 1]);
  }
};
