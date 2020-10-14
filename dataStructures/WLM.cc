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
  void resize(int n) { data.resize((n + sz - 1) / sz); }
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
template<typename T = int>
struct WLM {
  static inline int bit(T n, int i) { return n >> i & 1; }
  T H;
  vector<BV<uint64_t>> bvs;
  vi zs;
  WLM(vector<T> v, T hi) : H{64 - __builtin_clzll(hi)}, bvs(H), zs(H) {
    int n = SZ(v);
    for (int h = H - 1; ~h; --h) {
      bvs[h].resize(n);
      F0R (i, n) if (bit(v[i], h)) bvs[h].set(i); 
      bvs[h].build();
      auto it = stable_partition(ALL(v), [=](T i){ return !bit(i, h); });
      zs[h] = distance(v.begin(), it);
    }
  }
  // k-th smallest in [l, r)
  T kthsmallest(int l, int r, int k) {
    T lo = 0, hi = (T)1 << H;
    for (int h = H - 1; ~h; --h) {
      int have = bvs[h].rank0(r) - bvs[h].rank0(l);
      if (k < have) {
        hi -= (T)1 << h;
        l = bvs[h].rank0(l); r = bvs[h].rank0(r);
      } else {
        lo += (T)1 << h; k -= have;
        l = zs[h] + bvs[h].rank1(l); r = zs[h] + bvs[h].rank1(r);
      }
    }
    return lo;
  }
};
