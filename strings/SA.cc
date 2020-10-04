#include "../template.cc"
vii SA_ns, SA_bs;
using vit = vi::iterator;
template<int B = 'a', int S = 26, int N = 3>
struct SA {
  vi sa;
  SA(const string& s) {
    SA_bs.resize(max(S, SZ(s)) + 2);
    SA_ns.resize(max(S, SZ(s)) + 2);
    vi ra(SZ(s) + 1 + N);
    F0R (i, SZ(s)) ra[i] = s[i] - B + 2;
    ra[SZ(s)] = 1;
    sa = build(ra);
  }
  vi build(const vi& prefRank) {
    int n = SZ(prefRank) - N;
    int offset = n / N + !!(n % N);
    vi arr; arr.reserve(n);
    array<int, N> offs;
    F0R (j, N) {
      offs[j] = SZ(arr) - offset;
      for (int i = j; i < n; i += N) arr.pb(i);
    }
    rsort(offset + ALL(arr), N, [&](int i, int it) { return prefRank[i + it]; });
    vi ra(n - offset + N);
    int r = 1;
    FOR (i, offset, n) {
      ra[offs[arr[i] % N] + arr[i] / N] = r;
      if (i + 1 < n)
        F0R (j, N)
          if (prefRank[arr[i] + j] != prefRank[arr[i + 1] + j]) {
            r++; break;
          }
    }
    if (r < n - offset) {
      vi got(build(ra));
      F0R (i, SZ(got)) ra[got[i]] = i;
      FOR (j, 1, N) for (int i = 0; j + i * N < n; ++i)
        arr[offset + ra[offs[j] + i]] = j + i * N;
    }
    rsort(arr.begin(), arr.begin() + offset, 2, [&](int i, int it) {
      return it ? ra[offs[(i + 1) % N] + (i + 1) / N] : prefRank[i];
    });
    vi tmp(arr.begin(), arr.begin() + offset);
    int o = 0, m = offset, i = 0;
    while (o < offset && m < n) {
      int c = 0;
      for (int k = 0; !c; ++k) {
        int a = tmp[o] + k, b = arr[m] + k;
        c = (a % N && b % N) 
          ? cmp(ra[offs[a % N] + a / N], ra[offs[b % N] + b / N]) 
            : cmp(prefRank[a], prefRank[b]);
      }
      arr[i++] = c < 0 ? tmp[o++] : arr[m++];
    }
    while (o < offset) arr[i++] = tmp[o++];
    return arr;
  }
  static inline int cmp(int a, int b) { return (a > b) - (a < b); }
  template<typename F>
  static void rsort(vit vb, vit ve, int iters, F bf) {
    for (int d = iters - 1; ~d; --d) {
      int mx = 0;
      F0R (i, distance(vb, ve)) {
        int b = bf(*(vb + i), d);
        for (; mx <= b; ++mx) SA_bs[mx].fi = -1;
        if (SA_bs[b].fi == -1) SA_bs[b] = mp(i, i);
        SA_ns[SA_bs[b].se].se = i;
        SA_ns[i] = mp(*(vb + i), -1);
        SA_bs[b].se = i;
      }
      vit j = vb;
      F0R (i, mx)
        for (int it = SA_bs[i].fi; ~it; it = SA_ns[it].se, ++j)
          *j = SA_ns[it].fi;
    }
  }
};
