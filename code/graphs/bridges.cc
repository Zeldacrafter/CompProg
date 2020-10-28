#include "../template.cc"
vvi adj;
vi dfsNum, low;
int dfsCounter = 0;
int bridgeDfs(int v, vii& b, int p = -1) {
  dfsNum[v] = low[v] = dfsCounter++;
  for (int u : adj[v]) {
    if (dfsNum[u] == -1) {
      ckmin(low[v], bridgeDfs(u, b, v));
      if (low[u] > dfsNum[v]) b.eb(v, u);
    } else if (u != p)
      ckmin(low[v], dfsNum[u]);
  }
  return low[v];
}
vii findBridges() {
  vii bridges;
  dfsNum.assign(SZ(adj), -1);
  low.assign(SZ(adj), -1);
  F0R (v, SZ(adj))
    if (dfsNum[v] == -1) bridgeDfs(v, bridges);
  return bridges;
}
