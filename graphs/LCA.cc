#include "../template.cc"
struct LCA {
  vi height, eulerTour, first;
  vvi idx;
  LCA(vvi& adj, int root = 0)
      : height(SZ(adj), -1), first(SZ(adj), -1) {
    dfs(adj, root);
    build();
  }
  void build() {
    const int logn = ceil(log2l(SZ(eulerTour))) + 1;
    idx.assign(SZ(eulerTour), vi(logn));
    F0R (i, SZ(eulerTour))
      idx[i][0] = eulerTour[i];
    for (int j = 1; (1 << j) <= SZ(eulerTour); ++j)
      for (int i = 0; i + (1 << j) <= SZ(eulerTour); ++i) {
        int k = i + (1 << (j - 1));
        idx[i][j] = height[idx[i][j - 1]] < height[idx[k][j - 1]]
			? idx[i][j - 1] : idx[k][j - 1];
      }
  }
  int rmq(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return height[idx[l][k]] < height[idx[r - (1 << k) + 1][k]]
               ? idx[l][k] : idx[r - (1 << k) + 1][k];
  }
  void dfs(vvi& adj, int v = 0, int h = 0) {
    eulerTour.pb(v);
    first[v] = SZ(eulerTour) - 1;
    height[v] = h;
    for (int u : adj[v])
      if (first[u] == -1) {
        dfs(adj, u, h + 1);
        eulerTour.pb(v);
      }
  }
  int lca(int a, int b) {
    return rmq(min(first[a], first[b]), max(first[a], first[b]));
  }
};
