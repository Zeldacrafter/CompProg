#include "../template.cc"
struct LCA {
  int timer = 0, logN, root;
  vi tin, tout;
  vvi up, weight;
  LCA(vvii& adj, int root = 0)
      : logN(31 - __builtin_clz(SZ(adj))), root(root),
        tin(SZ(adj)), tout(SZ(adj)),
        up(SZ(adj), vi(logN + 1, root)),
        weight(SZ(adj), vi(logN + 1, root)) {
    lcadfs(adj, root);
  }
  void lcadfs(vvii& adj, int v, int p = -1,
              int w = numeric_limits<int>::min()) {
    tin[v] = ++timer;
    up[v][0] = ~p ? p : root;
    weight[v][0] = w;
    FOR (i, 1, logN + 1) {
      up[v][i] = up[up[v][i - 1]][i - 1];
      weight[v][i] =
          max(weight[v][i - 1], weight[up[v][i - 1]][i - 1]);
    }
    for (auto [u, w] : adj[v])
      if (u != p) lcadfs(adj, u, v, w);
    tout[v] = ++timer;
  }
  bool isAnc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
  }
  int lca(int v, int u) {
    if (isAnc(v, u)) return v;
    if (isAnc(u, v)) return u;
    for (int l = logN; ~l; --l)
      if (!isAnc(up[v][l], u)) v = up[v][l];
    return up[v][0];
  }
  // returns max weight of an edge on the the path v -- u
  int maxPath(int v, int u) {
    int anc = lca(v, u);
    return max(maxPathAnc(v, anc), maxPathAnc(u, anc));
  }
  // returns max weight of an edge on path from v to u (isAnc(u, v))
  int maxPathAnc(int v, int u) {
    int res = numeric_limits<int>::min();
    for (int l = logN; ~l; --l)
      if (isAnc(u, up[v][l])) {
        ckmax(res, weight[v][l]);
        v = up[v][l];
      }
    return res;
  }
};
