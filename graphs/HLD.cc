#include "../dataStructures/STIT.cc"
struct HLD {
  int n;
  vi par, sz, stidx, pos;
  vi first, stsz;
  vector<ST> sts;
  HLD(vvi& adj, vector<ll> val, int root = 0)
      : n{SZ(adj)}, par(n), sz(n, 1), stidx(n, -1), pos(n) {
    dfssz(adj, root);
    dfsbuild(adj, root);
    for (int i : stsz) sts.eb(i);
    F0R (i, n) {
      if (~stidx[i]) {
        auto& s = sts[stidx[i]];
        s.data[s.n + pos[i]] = val[i];
      }
    }
    for (auto& s : sts) s.build();
  }
  void dfssz(vvi& adj, int v, int p = -1) {
    par[v] = p;
    for (int u : adj[v]) {
      if (p != u) {
        dfssz(adj, u, v);
        sz[v] += sz[u];
      }
    }
  }
  void dfsbuild(vvi& adj, int v, int p = -1, bool heavy = false) {
    if (heavy) {
      ++stsz[stidx[v] = stidx[p]];
      pos[v] = pos[p] + 1;
    } else {
      stidx[v] = SZ(stsz);
      stsz.pb(1); first.pb(v);
    }
    for (int u : adj[v])
      if (p != u) dfsbuild(adj, u, v, sz[u] > sz[v] / 2);
  }
  void update(int v, ll val) { sts[stidx[v]].update(pos[v], val); }
  ll query(int up, int down) {
    ll sum = 0;
    while (stidx[up] != stidx[down]) {
      sum += sts[stidx[down]].query(0, pos[down] + 1);
      down = par[first[stidx[down]]];
    }
    sum += sts[stidx[up]].query(pos[up], pos[down] + 1);
    return sum;
  }
};
