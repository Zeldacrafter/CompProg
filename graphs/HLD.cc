#include "../dataStructures/STIT.cc"
struct HLD {
  int n;
  vi par, sz, stidx, pos, height;
  vi first, stsz;
  vi order;
  ST st;
  HLD(vvi& adj, vector<ll> val, int root = 0)
    : n{SZ(adj)}, par(n), sz(n, 1), stidx(n, -1), pos(n), height(n), st{n} {
    dfssz(adj, root);
    dfsbuild(adj, root);
    dfs27(adj, root);
    reverse(ALL(order));
    vi stpos(SZ(stsz));
    F0R (i, SZ(order)) {
      stpos[order[i]] = i;
    }
    vi offset(SZ(stsz));
    offset[0] = 0;
    F0R (i, SZ(order) - 1) {
      offset[i + 1] = offset[i] + stsz[order[i]];
    }
    F0R (i, n) {
      if (~stidx[i]) {
        pos[i] += offset[stpos[stidx[i]]];
        st.data[st.n + pos[i]] = val[i];
      }
    }
    st.build();
  }
  void dfssz(vvi& adj, int v, int h = 0, int p = -1) {
    par[v] = p;
    height[v] = h;
    for (int u : adj[v]) {
      if (p != u) {
        dfssz(adj, u, h + 1, v);
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
  void dfs27(vvi& adj, int v, int p = -1) {
    for (int u : adj[v]) {
      if (u != p) {
        dfs27(adj, u, v);
      }
    }
    if (first[stidx[v]] == v) {
      order.pb(stidx[v]);
    }
  }
  void update(int v, ll val) { st.update(pos[v], val); }
  ll queryPath(int a, int b) {
    ll sum = 0;
    while (stidx[a] != stidx[b]) {
      if (height[a] < height[b]) swap(a, b);
      sum += st.query(pos[first[stidx[a]]], pos[a] + 1);
      a = par[first[stidx[a]]];
    }
    if (height[a] > height[b]) swap(a, b);
    sum += st.query(pos[a], pos[b] + 1);
    return sum;
  }
  ll querySubtree(int v) {
    return st.query(pos[v], pos[v] + sz[v]);
  }
};
