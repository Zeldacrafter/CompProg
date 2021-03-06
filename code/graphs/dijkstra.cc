#include "../template.hh"
const int inf = 1e9;
vvii adj;
vi dijkstra(int start) {
  vi dist(SZ(adj), inf);
  set<ii> q;
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
