#include "../template.cc"
vii SA_ns, SA_bs;
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
    // - consolidate one and more into one array and work with iterators
    //   - further can the consolidated array be used as the result
    //     array with (semi-)inplace-merging.  Approaches:
    //      1. allocate extra SZ(prefRank) / N to store the one part.
    //         This gives enough space to merge inplace
    // - get rid of the pos array.  Ideas:
    //   1. use idx calcultion:
    //      a. more[i] -> offset[more[i] % N] + more[i] / N;
    //      b. pos[i] -> ...
    int n = SZ(prefRank) - N;
    vi one; one.reserve((n + N - 1)/N);
    for (int i = 0; i < n; i += N) one.pb(i);
    vi more; more.reserve(n - SZ(one));
    FOR (j, 1, N)
      for (int i = j; i < n; i += N)
        more.pb(i);
    vi pos(n + N, SZ(more)); 
    F0R (i, SZ(more)) pos[more[i]] = i;
    rsort(more, N, [&](int i, int it) { return prefRank[i + it] + 1; });
    vi ra(SZ(more) + N, -1);
    int r = 0;
    F0R (i, SZ(more)) {
      ra[pos[more[i]]] = r;
      if (i + 1 < SZ(more))
        F0R (j, N)
          if (prefRank[more[i] + j] != prefRank[more[i + 1] + j]) {
            r++; break;
          }
    }
    if (r + 1 < SZ(more)) {
      vi got(build(ra));
      F0R (i, SZ(got)) ra[got[i]] = i;
      F0R (i, SZ(pos)) 
        if (pos[i] < SZ(more)) 
          more[ra[pos[i]]] = i;
    }
    rsort(one, 2, [&](int i, int it) {
      return it ? ra[pos[i + 1]] + 1 : prefRank[i];
    });
    vi res; res.reserve(n);

    int o = 0, m = 0;
    while (o < SZ(one) && m < SZ(more)) {
      int c = 0;
      for (int k = 0; !c; ++k) {
        int a = one[o] + k, b = more[m] + k;
        c = (a % N && b % N) 
          ? cmp(ra[pos[a]], ra[pos[b]]) 
            : cmp(prefRank[a], prefRank[b]);
      }
      res.pb(c < 0 ? one[o++] : more[m++]);
    }
    while (m < SZ(more)) res.pb(more[m++]);
    while (o < SZ(one)) res.pb(one[o++]);

    return res;
  }
  static inline int cmp(int a, int b) { return (a > b) - (a < b); }
  static void rsort(vi& v, int iters, function<int(int, int)> bf) {
    for (int d = iters - 1; ~d; --d) {
      int mx = 0;
      F0R (i, SZ(v)) {
        int b = bf(v[i], d);
        for (; mx <= b; ++mx) SA_bs[mx].fi = -1;
        if (SA_bs[b].fi == -1)
          SA_bs[b] = mp(i, i);
        SA_ns[SA_bs[b].se].se = i;
        SA_ns[i] = mp(v[i], -1);
        SA_bs[b].se = i;
      }
      int j = 0;
      F0R (i, mx)
        for (int it = SA_bs[i].fi; ~it; it = SA_ns[it].se)
          v[j++] = SA_ns[it].fi;
    }
  }
};
