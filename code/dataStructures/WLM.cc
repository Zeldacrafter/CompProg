#include "BV.cc"
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
  T kthsmallest(int l, int r, int k) { // k-th smallest in [l, r)
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
  int greater(int l, int r, int k) { // elements >= k in [l, r)
    T lo = 0, hi = (T)1 << H;
    int ans = 0;
    for (int h = H - 1; ~h; --h) {
      T d = (T)1 << h;
      if (k <= lo + d) {
        hi -= d;
        ans += bvs[h].rank1(r) - bvs[h].rank1(l);
        l = bvs[h].rank0(l); r = bvs[h].rank0(r);
      } else {
        lo += d;
        l = zs[h] + bvs[h].rank1(l); r = zs[h] + bvs[h].rank1(r);
      }
    }
    return ans;
  };
};
