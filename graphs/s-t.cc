// edge implementation is the same as in
// Edmonds Karp w/ adjacency lists
vector<edge> edges;
vvi adj(V);
vi visited(V, 0);
vi found;
// start w/ source for the s-part of the cut
// start w/ sink for the t-part of the cut
void dfs(int v) {
  visited[v] = 1;
  found.pb(v);
  for (int i : adj[v]) {
    if (!visited[edges[i].to(v)] &&
        edges[i].curf(v) < edges[i].mf(v))
      dfs(edges[i].to(v));
  }
}
