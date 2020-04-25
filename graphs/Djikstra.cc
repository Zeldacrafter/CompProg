#include "../template.cc"
const int inf = 1e9;
void djikstra(vvii& adj, vi& dist, int start) {
  dist.assign(SZ(adj), inf);
  auto cmp = [](ii& a, ii& b) -> bool { return a.se > b.se; };
  priority_queue<ii, vii, decltype(cmp)> q(cmp);
  q.push(mp(start, 0));
  dist[start] = 0;
  while (!q.empty()) {
    int v = q.top().fi;
    int d = q.top().se;
    q.pop();
    if (dist[v] < d) continue;
    for (ii p : adj[v])
      if (ckmin(dist[p.fi], d + p.se)) q.push(mp(p.fi, d + p.se));
  }
}
