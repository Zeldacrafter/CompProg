#include "../template.cc"
const int inf = 1e9;
bool bellmanFordQueue(vvii& adj, vi& dist,
                      int start) {
  const int n = SZ(adj);
  dist.assign(n, inf);
  queue<int> q;
  vector<bool> inQ(n, false);
  // count number relaxations for every
  // vertex to account for negative circles
  vi cnt(n, 0);
  q.push(start);
  dist[start] = 0;
  inQ[start] = true;
  while (!q.empty()) {
    int v = q.ft;
    q.pop();
    inQ[v] = false;
    for (ii i : adj[v]) {
      if (ckmin(dist[i.fi],
                dist[v] + i.se)) {
        if (++cnt[i.fi] > n) return false;
        if (!inQ[i.fi]) {
          q.push(i.fi);
          inQ[i.fi] = true;
        }
      }
    }
  }

  return true;
}
