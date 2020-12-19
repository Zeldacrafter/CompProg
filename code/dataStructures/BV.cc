#include "../template.cc"
template <typename T>
struct BV {
  static constexpr int sz = sizeof(T) * 8;
  struct BLK {
    T bits = 0;
    int sum = 0;
    int rank() { return __builtin_popcountll(bits); }
    int rank(int i) {
      return __builtin_popcountll(bits & (((T)1 << i) - (T)1));
    }
  };
  vector<BLK> data;
  void resize(int n) { data.resize(n / sz + 1); }
  int rank1(int idx) { // ones in [0, idx)
    return data[idx / sz].sum + data[idx / sz].rank(idx % sz);
  }
  int rank0(int idx) { return idx - rank1(idx); } // zeroes in [0, idx)
  void set(int i) { data[i / sz].bits |= (T)1 << (i % sz); }
  int get(int i) { return data[i / sz].bits >> (i % sz) & 1; }
  void build() {
    data[0].sum = 0;
    FOR (i, 1, SZ(data))
      data[i].sum = data[i - 1].sum + data[i - 1].rank();
  }
};
