#include "../template.cc"
const int UNVISITED = -1;
int N;
vvi adj(N);
vi dfs_num(N, UNVISITED), dfs_low(N, 0), S;
vector<bool> onStack(N, false);
int dfsCounter = 0, numSCC = 0;
void scc(int v) {
  dfs_num[v] = dfs_low[v] = dfsCounter++;
  S.push_back(v);
  onStack[v] = true;
  for (int j : adj[v]) {
    if (dfs_num[j] == UNVISITED) scc(j);
    if (onStack[j]) dfs_low[v] = min(dfs_low[j], dfs_low[v]);
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
