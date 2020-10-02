#include "../template.cc"
vii SA_ns, SA_bs;
using vit = vi::iterator;
template<int B = 'a', int S = 26, int N = 3>
struct SA {
  vi sa;
  SA(const string& s) {
    SA_bs.resize(max(S, SZ(s)) + 1);
    SA_ns.resize(max(S, SZ(s)) + 1);
    vi ra(SZ(s) + 1 + N, -1);
    F0R (i, SZ(s)) ra[i] = s[i] - B + 1;
    ra[SZ(s)] = 0;
    sa = build(ra);
  }
  vi build(const vi& prefRank) {
    // optimization ideas:
    // - get rid of the pos array.  Ideas:
    //   1. use idx calcultion:
    //      a. more[i] -> offset[more[i] % N] + more[i] / N;
    //      b. pos[i] -> ...
    int n = SZ(prefRank) - N;
    int offset = n / N + !!(n % N);
    vi arr; arr.reserve(n);
    F0R (j, N) for (int i = j; i < n; i += N) arr.pb(i);
    vi pos(n + N, n - offset); 
    F0R (i, n - offset) pos[arr[i + offset]] = i;
    rsort(offset + ALL(arr), N, [&](int i, int it) { return prefRank[i + it] + 1; });
    vi ra(n - offset + N, -1);
    int r = 0;
    FOR (i, offset, n) {
      ra[pos[arr[i]]] = r;
      if (i + 1 < n)
        F0R (j, N)
          if (prefRank[arr[i] + j] != prefRank[arr[i + 1] + j]) {
            r++; break;
          }
    }
    if (r + 1 < n - offset) {
      vi got(build(ra));
      F0R (i, SZ(got)) ra[got[i]] = i;
      F0R (i, SZ(pos)) 
        if (pos[i] < n - offset) 
          arr[offset + ra[pos[i]]] = i;
    }
    rsort(arr.begin(), arr.begin() + offset, 2, [&](int i, int it) {
      return it ? ra[pos[i + 1]] + 1 : prefRank[i];
    });
    vi tmp(arr.begin(), arr.begin() + offset);
    int o = 0, m = offset, i = 0;
    while (o < offset && m < n) {
      int c = 0;
      for (int k = 0; !c; ++k) {
        int a = tmp[o] + k, b = arr[m] + k;
        c = (a % N && b % N) 
          ? cmp(ra[pos[a]], ra[pos[b]]) 
            : cmp(prefRank[a], prefRank[b]);
      }
      arr[i++] = c < 0 ? tmp[o++] : arr[m++];
    }
    while (o < offset) arr[i++] = tmp[o++];
    return arr;
  }
  static inline int cmp(int a, int b) { return (a > b) - (a < b); }
  static void rsort(vit vb, vit ve, int iters, function<int(int, int)> bf) {
    for (int d = iters - 1; ~d; --d) {
      int mx = 0;
      F0R (i, distance(vb, ve)) {
        int b = bf(*(vb + i), d);
        for (; mx <= b; ++mx) SA_bs[mx].fi = -1;
        if (SA_bs[b].fi == -1)
          SA_bs[b] = mp(i, i);
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
