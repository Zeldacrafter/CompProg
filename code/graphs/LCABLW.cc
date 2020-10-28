#include "../template.hh"

template <typename T, typename F>
struct LCA {
  int n, logN, root, e;
  F f;
  vvi up;
  vector<vector<T>> weight;
  vi h;
  LCA(vector<vector<pair<int, T>>>& adj, F _f, T _e, int r = 0)
      : n{SZ(adj)}, logN{31 - __builtin_clz(n)},
        root{r}, e{_e}, f{_f},
        up(n, vi(logN + 1, root)), 
        weight(n, vector<T>(logN + 1, _e)), h(n, -1) { 
    build(adj);
  }
  void build(vector<vector<pair<int, T>>>& adj) {
    queue<int> q;
    q.push(root);
    h[root] = 0;
    while (SZ(q)) {
      int v = q.front();
      q.pop();
      for (auto [u, w] : adj[v])
        if (h[u] == -1) {
          h[u] = h[v] + 1;
          q.push(u);
          up[u][0] = v;
          weight[u][0] = w;
        }
    }
    FOR (exp, 1, logN + 1)
      F0R (v, n)
        if (up[v][exp - 1] != -1) {
          up[v][exp] = up[up[v][exp - 1]][exp - 1];
          weight[v][exp] = f(weight[v][exp - 1], 
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
  int pathQuery(int v, int u) {
    int anc = lca(v, u);
    return f(pathQueryAnc(v, anc), pathQueryAnc(u, anc));
  }
  int pathQueryAnc(int v, int u) {
    int res = e;
    for (int l = logN; ~l; --l) {
      if (up[v][l] != -1 && h[u] <= h[up[v][l]]) {
        res = f(res, weight[v][l]);
        v = up[v][l];
      }
    }
    return res;
  }
};
