#include "flowedge.cc"
const ll inf = 10e12;
ll augment(int s, int t) {
  vii p(SZ(adj), mp(-1, -1));
  queue<int> q;
  p[s] = mp(-2, 0);
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    if (v == t) break;
    q.pop();
    for (int i : adj[v]) {
      edge& e = edges[i];
      if (p[e.other(v)] == mp(-1, -1) && e.flow(v) < e.capacity(v)) {
	p[e.other(v)] = mp(v, i); q.push(e.other(v));
      }
    }
  }
  if (p[t] == mp(-1, -1)) return 0;
  ll mf = inf;
  for (ii c = p[t]; c.fi != -2; c = p[c.fi])
    ckmin(mf, edges[c.se].capacity(c.fi) - edges[c.se].flow(c.fi));
  for (ii c = p[t]; c.fi != -2; c = p[c.fi])
    edges[c.se].adjust(c.fi, mf);
  return mf;
}
ll maxflow(int s, int t) {
  ll maxflow = 0;
  while (ll plus = augment(s, t)) maxflow += plus;
  return maxflow;
}
