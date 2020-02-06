int V;
vii adj(V);
vi visited(V, 0), p(V, -1);
void dfs(int curr) {
  visited[curr] = 1;
  for (int v : adj[curr])
    if (!visited[v]) p[v] = curr, dfs(v);
}
int main() {
  for (int v = 0; v < V; ++v)
    if (!visited[v]) dfs(v);
}
