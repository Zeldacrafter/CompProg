#include "../dataStructures/STIT.cc"
template<typename T, typename F>
struct HLD {
  int n;
  vi par, sz, height, in, pos;
  vvi paths;
  ST<T, F> st;
  HLD(vvi& adj, const vector<T>& val,
      T unit, F merge, int root = 0)
    : n{SZ(adj)}, par(n), sz(n, 1), height(n), in(n), pos(n),
      st{n, unit, merge} {
    dfssz(adj, root);
    vi order;
    dfsbuild(adj, root, order);
    int j = 0;
    for (auto it = order.crbegin(); it != order.crend(); ++it)
      for (int v : paths[*it]) st.data[st.n + (pos[v] = j++)] = val[v];
    st.build();
  }
  int dfssz(vvi& adj, int v, int h = 0, int p = -1) {
    par[v] = p; height[v] = h;
    for (int u : adj[v])
      if (p != u) sz[v] += dfssz(adj, u, h + 1, v);
    return sz[v];
  }
  void dfsbuild(vvi& adj, int v, vi& order, int p = -1, bool hvy = false) {
    if (hvy) paths[in[v] = in[p]].pb(v); 
    else {
      in[v] = SZ(paths);
      paths.pb({v});
    }
    int h = -1;
    for (int u : adj[v])
      if (p != u) {
        if (sz[u] > sz[v] / 2) h = u;
        else dfsbuild(adj, u, order, v);
      }
    if (~h) dfsbuild(adj, h, order, v, true);
    if (paths[in[v]][0] == v) order.pb(in[v]);
  }
  void update(int v, T val) { st.update(pos[v], val); }
  T queryPath(int a, int b) {
    T v = st.e;
    while (in[a] != in[b]) {
      if (height[paths[in[a]][0]] < height[paths[in[b]][0]]) swap(a, b);
      v = st.merge(v, st.query(pos[paths[in[a]][0]], pos[a] + 1));
      a = par[paths[in[a]][0]];
    }
    if (height[a] > height[b]) swap(a, b);
    return st.merge(v, st.query(pos[a], pos[b] + 1));
  }
  T querySubtree(int v) {
    return st.query(pos[v], pos[v] + sz[v]);
  }
};
