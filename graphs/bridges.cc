#include "../template.cc"
vi dfsNum, low;
int dfsCounter = 0;
int bridgeDfs(int v, vvi& adj, vii& b, int p = -1) {
  dfsNum[v] = low[v] = dfsCounter++;
  for (int u : adj[v]) {
    if (u == p) continue;
    if (dfsNum[u] == -1) {
      ckmin(low[v], bridgeDfs(u, adj, b, v));
      if (low[u] > dfsNum[v]) b.eb(v, u);
    } else
      ckmin(low[v], dfsNum[u]);
  }
  return low[v];
}
void findBridges(vvi& adj, vii& bridges) {
  dfsNum.assign(SZ(adj), -1);
  low.assign(SZ(adj), -1);
  F0R (v, SZ(adj))
    if (dfsNum[v] == -1) bridgeDfs(v, adj, bridges);
}
