#include "../template.hh"
const int inf = 1e9;
vvii adj;
// returns empty vector if there's a neg cycle
vi bellmanFordQueue(int start) {
  vi dist(SZ(adj), inf);
  queue<int> q;
  vector<bool> inQ(SZ(adj), false);
  vi cnt(SZ(adj), 0); // cnt number of relaxations for neg cycles
  q.push(start);
  dist[start] = 0; inQ[start] = true;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    inQ[v] = false;
    for (auto [u, d] : adj[v])
      if (ckmin(dist[u], dist[v] + d)) {
	  if (++cnt[u] > SZ(adj)) return vi();
        if (!inQ[u]) q.push(u), inQ[u] = true;
      }
  }
  return dist;
}
