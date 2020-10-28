#include "../template.cc"
vvi adj;
vi dfs_num, dfs_low, S;
vector<bool> onStack;
int dfsCounter;
void scc(int v, vvi& sccs) {
  dfs_num[v] = dfs_low[v] = dfsCounter++;
  S.push_back(v);
  onStack[v] = true;
  for (int u : adj[v]) {
    if (dfs_num[u] == -1) scc(u, sccs);
    if (onStack[u]) ckmin(dfs_low[v], dfs_low[u]);
  }
  if (dfs_num[v] == dfs_low[v]) {
    sccs.eb(); int u;
    do {
      u = S.back();
      S.pop_back();
      onStack[u] = 0;
      sccs.back().pb(u);
    } while (u != v);
  }
}
vvi scc() {
    dfs_num.assign(SZ(adj), -1);
    dfs_low.assign(SZ(adj), 0);
    onStack.assign(SZ(adj), 0);
    dfsCounter = 0;
    vvi sccs;
    F0R (i, SZ(adj))
	if (!~dfs_num[i]) scc(i, sccs);
    return sccs;
}
