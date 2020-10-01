#include "../template_long.cc"
vii SA_ns, SA_bs;
template<int B = 'a', int S = 26, int N = 3>
struct SA {
  template<typename T>
  static inline int cmp(T a, T b) {
    return (a > b) - (a < b);
  }
  template<typename T>
  static inline T getOr(const vector<T>& v, const int idx, T alternative) {
    return idx < SZ(v) ? v[idx] : alternative;
  }
  template<int I>
  static void rsort(vi& v, function<int(int, int)> bf) {
    for (int d = I - 1; ~d; --d) {
      int mx = 0;
      F0R (i, SZ(v)) {
        int b = bf(v[i], d);
        if (b >= mx) {
          fill(SA_bs.begin() + mx, SA_bs.begin() + b + 1, mp(-1, -1));
          mx = b + 1;
        }
        if (SA_bs[b].fi == -1) {
          SA_bs[b] = mp(i, i);
        }
        SA_ns[SA_bs[b].se].se = i;
        SA_ns[i] = mp(v[i], -1);
        SA_bs[b].se = i;
      }
      for (int j = 0, i = 0; i < mx; ++i) {
        for (int it = SA_bs[i].fi; ~it; it = SA_ns[it].se) {
          v[j++] = SA_ns[it].fi;
        }
      }
    }
  }
  vi sa;
  vi build(const vi& pref) {
    vi one; one.reserve(SZ(pref) + 1);
    for (int i = 0; i < SZ(pref); i += N) {
      one.pb(i);
    }
    vi more; more.reserve(SZ(pref) - SZ(one));
    FOR (j, 1, N) {
      for (int i = j; i < SZ(pref); i += N) {
        more.pb(i);
      }
    }
    vi pos(SZ(pref), -1); 
    F0R (i, SZ(more)) {
      pos[more[i]] = i;
    }
    rsort<N>(more, [&](int i, int it) {
      return getOr(pref, i + it, -1) + 1;
    });
    vi ra(SZ(more));
    bool rec = false;
    for (int r = 0, i = 0; i < SZ(more); ++i) {
      ra[pos[more[i]]] = r;
      if (i && ra[pos[more[i - 1]]] == r) rec = true;
      if (i + 1 < SZ(more)) {
        F0R (j, N) {
          if (getOr(pref, more[i] + j, -1) != getOr(pref, more[i + 1] + j, -1)) {
            ++r; break;
          }
        }
      }
    }
    if (rec) {
      vi got = build(ra);
      F0R (i, SZ(got)) {
        ra[got[i]] = i;
      }
      F0R (i, SZ(pos)) {
        if (~pos[i]) {
          more[ra[pos[i]]] = i;
        }
      }
    }
    rsort<2>(one, [&](int i, int it) {
      if (it) return getOr(ra, getOr(pos, i + 1, SZ(ra)), -1) + 1;
      return pref[i];
    });
    vi res; res.reserve(SZ(pref));
    for (int o = 0, m = 0; o < SZ(one) || m < SZ(more);) {
      if (o == SZ(one))  {
        res.pb(more[m++]);
      } else if (m == SZ(more)) {
        res.pb(one[o++]);
      } else {
        int c = 0;
        for (int k = 0; !c; ++k) {
          int a = one[o] + k, b = more[m] + k;
          if (a % N == 0 || b % N == 0) {
            c = cmp(getOr(pref, a, -1), getOr(pref, b, -1));
          } else {
            c = cmp(getOr(ra, getOr(pos, a, -1), -1), getOr(ra, getOr(pos, b, -1), -1));
          }
        }
        if (c < 0) {
          res.pb(one[o++]);
        } else {
          res.pb(more[m++]);
        }
      }
    }
    return res;
  }
  SA(const string& s) {
    SA_bs.resize(max(S, SZ(s)) + 1);
    SA_ns.resize(max(S, SZ(s)) + 1);
    vi v(SZ(s) + 1);
    iota(ALL(v), 0);
    vi ra(SZ(v));
    F0R (i, SZ(s)) {
      ra[i] = s[i] - B + 1;
    }
    ra[SZ(s)] = 0;
    sa = build(ra);
  }
};

