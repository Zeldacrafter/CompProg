#include "../dataStructures/SPT.cc"
struct LCA {
  vi height, first;
  SPT<int, function<int(int, int)>> spt;
  LCA(vvi& adj, int root = 0) : height(SZ(adj), -1), first(SZ(adj), -1),
      spt(2 * SZ(adj) - 1, [self = this](int a, int b) {
        return self->height[a] < self->height[b] ? a : b;
      }) {
    int idx = 0;
    dfs(adj, root, idx);
    spt.build();
  }
  void dfs(vvi& adj, int v, int& idx, int h = 0) {
    first[v] = idx;
    spt.d[0][idx++] = v;
    height[v] = h;
    for (int u : adj[v]) if (first[u] == -1) {
      dfs(adj, u, idx, h + 1);
      spt.d[0][idx++] = v;
    }
  }
  int lca(int a, int b) {
    ii m = minmax(first[a], first[b]);
    return spt.query(m.fi, m.se);
  }
};
