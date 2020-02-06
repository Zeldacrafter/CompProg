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
      if (!visited[v]) {
        q.push(v),
        visited[v] = true,
        p[v] = curr;
  }
}
int main() {
  F0R(v, V)
    if (!visited[v])
        bfs(v);
}
