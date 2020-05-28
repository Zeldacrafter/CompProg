#include "flowedge.cc"
vi visited;
void dfs(int v, vi& found) {
  visited[v] = 1;
  found.pb(v);
  for (int i : adj[v]) {
    if (!visited[edges[i].other(v)] &&
        edges[i].flow(v) < edges[i].capacity(v))
      dfs(edges[i].other(v), found);
  }
}
pair<vi, vi> findcut(int s, int t) {
  vi scut, tcut;
  visited.assign(SZ(adj), 0);
  dfs(s, scut);
  dfs(t, tcut);
  return mp(scut, tcut);
}
