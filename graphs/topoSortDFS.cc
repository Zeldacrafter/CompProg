#include "../template.cc"
int N;
vvi adj(N);
vi visited(N, 0);
vi ts;  // topo sort in reverse order
void dfs(int v) {
  visited[v] = 1;
  for (int u : adj[v])
    if (!visited[u]) dfs(u);
  ts.push_back(v);
}
int main() {
  F0R (v, N)
    if (!visited[v]) dfs(v);
  ROFI (it, ts)
    cout << *it << '\n';
}
