#include "../template.cc"
vvi adj;
vi visited, p;
void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int v : adj[curr])
      if (!visited[v]) q.push(v), visited[v] = true, p[v] = curr;
  }
}
int main() {
  visited.assign(SZ(adj), 0);
  p.assign(SZ(adj), -1);
  F0R (v, SZ(adj))
    if (!visited[v]) bfs(v);
}
