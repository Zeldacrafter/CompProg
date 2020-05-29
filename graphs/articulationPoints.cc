#include "../template.cc"
vi dfsNum, low;
int dfsCounter = 0;
vvi adj;
int artiDfs(int v, vi& a, int p = -1) {
  dfsNum[v] = low[v] = dfsCounter++;
  int children = 0;
  bool aP = false;
  for (int u : adj[v]) {
    if (dfsNum[u] == -1) {
      ckmin(low[v], artiDfs(u, a, v));
      if (low[u] >= dfsNum[v] && p != -1 && !aP) {
        a.pb(v);
        aP = true;
      }
      children++;
    } else if (u != p)
      ckmin(low[v], dfsNum[u]);
  }
  if (p == -1 && children > 1) a.pb(v);
  return low[v];
}
vi findArtiPoints(vvi& adj) {
  dfsNum.assign(SZ(adj), -1);
  low.assign(SZ(adj), -1);
  dfsCounter = 0;
  vi res;
  F0R (v, SZ(adj))
    if (dfsNum[v] == -1) artiDfs(v, res);
  return res;
}
