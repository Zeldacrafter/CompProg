#include "../template.cc"
int N;
vvi adj(N);
vi dfs_num(N, -1), dfs_low(N, 0), S;
vector<bool> onStack(N, false);
int dfsCounter = 0, numSCC = 0;
void scc(int v) {
  dfs_num[v] = dfs_low[v] = dfsCounter++;
  S.push_back(v);
  onStack[v] = true;
  for (int j : adj[v]) {
    if (dfs_num[j] == -1) scc(j);
    if (onStack[j]) ckmin(dfs_low[v], dfs_low[j]);
  }
  if (dfs_num[v] == dfs_low[v]) {
    numSCC++;
    while (1) {
      int u = S.back();
      S.pop_back();
      onStack[u] = false;
      if (u == v) break;
    }
  }
}
