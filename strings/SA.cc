#include "../template_long.cc"
vii SA_ns, SA_bs;
template<int B = 'a', int S = 26, int N = 3>
struct SA {
  static inline int cmp(int a, int b) { return (a > b) - (a < b); }
  static inline int getOr(const vi& v, int idx, int alternative = -1) {
    return idx < SZ(v) ? v[idx] : alternative;
  }
  static void rsort(vi& v, int iters, function<int(int, int)> bf) {
    for (int d = iters - 1; ~d; --d) {
      int mx = 0;
      F0R (i, SZ(v)) {
        int b = bf(v[i], d);
        if (b >= mx) {
          fill(SA_bs.begin() + mx, SA_bs.begin() + b + 1, mp(-1, -1));
          mx = b + 1;
        }
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
  vi sa;
  vi build(const vi& prefRank) {
    vi one; one.reserve((SZ(prefRank) + N - 1)/N);
    for (int i = 0; i < SZ(prefRank); i += N) one.pb(i);
    vi more; more.reserve(SZ(prefRank) - SZ(one));
    FOR (j, 1, N)
      for (int i = j; i < SZ(prefRank); i += N)
        more.pb(i);
    vi pos(SZ(prefRank), -1); 
    F0R (i, SZ(more)) pos[more[i]] = i;
    rsort(more, N, [&](int i, int it) { return getOr(prefRank, i + it) + 1; });
    vi ra(SZ(more));
    int r = 0;
    F0R (i, SZ(more)) {
      ra[pos[more[i]]] = r;
      if (i + 1 < SZ(more))
        F0R (j, N)
          if (getOr(prefRank, more[i] + j) != getOr(prefRank, more[i + 1] + j)) {
            r++; break;
          }
    }
    if (r + 1 < SZ(more)) {
      vi got = build(ra);
      F0R (i, SZ(got)) ra[got[i]] = i;
      F0R (i, SZ(pos)) 
        if (~pos[i]) 
          more[ra[pos[i]]] = i;
    }
    rsort(one, 2, [&](int i, int it) {
      return it ? getOr(ra, getOr(pos, i + 1, SZ(ra))) + 1 : prefRank[i];
    });
    vi res; res.reserve(SZ(prefRank));

    int o = 0, m = 0;
    while (o < SZ(one) && m < SZ(more)) {
      int c = 0;
      for (int k = 0; !c; ++k) {
        int a = one[o] + k, b = more[m] + k;
        c = (a % N && b % N) 
            ? cmp(getOr(ra, getOr(pos, a, SZ(ra))), getOr(ra, getOr(pos, b, SZ(ra)))) 
            : cmp(getOr(prefRank, a), getOr(prefRank, b));
      }
      res.pb(c < 0 ? one[o++] : more[m++]);
    }
    while (o == SZ(one) && m < SZ(more)) res.pb(more[m++]);
    while (m == SZ(more) && o < SZ(one)) res.pb(one[o++]);

    return res;
  }
  SA(const string& s) {
    SA_bs.resize(max(S, SZ(s)) + 1);
    SA_ns.resize(max(S, SZ(s)) + 1);
    vi ra(SZ(s) + 1);
    F0R (i, SZ(s)) ra[i] = s[i] - B + 1;
    sa = build(ra);
  }
};
