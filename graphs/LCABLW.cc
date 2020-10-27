#include "../template.cc"
struct LCA {
  int n, logN, root;
  vvi up, weight;
  vi h;
  LCA(vvii& adj, int r = 0)
      : n{SZ(adj)}, logN{31 - __builtin_clz(n)},
        root{r}, up(n, vi(logN + 1, root)),
        weight(n, vi(logN + 1, numeric_limits<int>::min())),
        h(n, -1) { 
    build(adj);
  }
  void build(vvii& adj) {
    queue<int> q;
    q.push(root);
    h[root] = 0;
    while (SZ(q)) {
      int v = q.front();
      q.pop();
      for (auto [u, _] : adj[v])
        if (h[u] == -1) {
          h[u] = h[v] + 1;
          q.push(u);
        }
    }
    F0R (v, n)
      for (auto [u, w] : adj[v])
        if (h[u] < h[v]) {
          up[v][0] = u;
          weight[v][0] = w;
        }
    FOR (exp, 1, logN + 1)
      F0R (v, n)
        if (up[v][exp - 1] != -1) {
          up[v][exp] = up[up[v][exp - 1]][exp - 1];
          weight[v][exp] = max(weight[v][exp - 1], 
                               weight[up[v][exp - 1]][exp - 1]);
        }
  }
  int jumpUp(int v, int amt) {
    for (int i = 0; v != -1 && (1 << i) <= amt; ++i)
      if (amt & (1 << i)) 
        v = up[v][i];
    return v;
  }
  int lca(int v, int u) {
    v = jumpUp(v, max(0, h[v] - h[u]));
    u = jumpUp(u, max(0, h[u] - h[v]));
    if (u == v) return u;
    for (int l = logN; ~l; --l) {
      int jmpU = up[u][l], jmpV = up[v][l];
      if (jmpU == -1 || jmpV == -1) continue;
      if (jmpU != jmpV) {
        u = jmpU;
        v = jmpV;
      }
    }
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
    for (int l = logN; ~l; --l) {
      if (up[v][l] != -1 && h[u] <= h[up[v][l]]) {
        ckmax(res, weight[v][l]);
        v = up[v][l];
      }
    }
    return res;
  }
};
