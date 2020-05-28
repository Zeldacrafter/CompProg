#include "../template.cc"
const int inf = 1e9;
vvii adj;
vi djikstra(int start) {
  vi dist(SZ(adj), inf);
  set<ii> q;
  q.emplace(0, start);
  dist[start] = 0;
  while (!q.empty()) {
    auto [d, v] = *q.begin(); q.erase(q.begin());
    if (dist[v] < d) continue;
    for (auto [u, du] : adj[v])
      if (ckmin(dist[u], d + du)) q.emplace(u, d + du);
  }
  return dist;
}
