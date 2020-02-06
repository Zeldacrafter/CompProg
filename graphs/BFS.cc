int V;
vvi adj(V);
vi visited(V, 0), p(V, -1);
void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int v : adj[curr])
      if (!visited[v])
        q.push(v), visited[v] = 1,
                   p[v] = curr;
  }
}
int main() {
  for (int v = 0; v < V; ++v)
    if (!visited[v]) bfs(v);
}
