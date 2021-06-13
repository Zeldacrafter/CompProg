#include "../template.hh"
template <typename D = int>
vector<D> dijkstra(int start, const vector<vector<pair<int, D>>>& adj, const D INF = 1e9) {
  vector<D> dist(SZ(adj), INF);
  set<pair<D, int>> q;
  q.emplace(0, start);
  dist[start] = 0;
  while (!q.empty()) {
    auto [d, v] = *q.begin(); q.erase(q.begin());
    if (dist[v] < d) continue;
    for (auto [u, du] : adj[v])
      if (ckmin(dist[u], d + du)) q.emplace(d + du, u);
  }
  return dist;
}
