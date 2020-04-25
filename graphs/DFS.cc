#include "../template.cc"
vvi adj;
vi visited, p;
void dfs(int curr) {
  visited[curr] = 1;
  for (int v : adj[curr])
    if (!visited[v]) p[v] = curr, dfs(v);
}
int main() {
  visited.assign(SZ(adj), 0);
  p.assign(SZ(adj), -1);
  for (int v = 0; v < SZ(adj); ++v)
    if (!visited[v]) dfs(v);
}
