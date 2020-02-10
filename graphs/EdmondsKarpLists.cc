const ll inf = 10e12;
struct edge {
  edge(int from, int to, ll maxf)
      : from(from),
        too(to),
        maxf(maxf),
        currentf(0) {}
  int from, too;
  ll maxf;
  ll currentf;
  int to(int v) {
    return v == from ? too : from;
  }
  ll mf(int v = 0) { return maxf; }
  ll curf(int v) {
    return v == from ? currentf
                     : maxf - currentf;
  }
  ll flow(int v) { return mf(v) - curf(v); }
  void adjust(int v, ll amount) {
    if (v == from)
      currentf += amount;
    else
      currentf -= amount;
  }
};
vector<edge> edges;
vvi adj(600);
ll augment(const ll s, const ll t) {
  vii p(t + 1, mp(-1, -1));
  queue<ll> q;
  p[s] = mp(-2, 0);
  q.push(0);
  while (!q.empty()) {
    ll v = q.front();
    if (v == t) break;
    q.pop();
    for (int i : adj[v]) {
      if (p[edges[i].to(v)] == mp(-1, -1) &&
          edges[i].curf(v) <
              edges[i].mf(v)) {
        p[edges[i].to(v)] = mp(v, i);
        q.push(edges[i].to(v));
      }
    }
  }
  if (p[t] == mp(-1, -1)) return 0;
  ll mf = inf;

  for (ii c = p[t]; c.fi != -2; c = p[c.fi])
    ckmin(mf, edges[c.se].flow(c.fi));

  for (ii c = p[t]; c.fi != -2; c = p[c.fi])
    edges[c.se].adjust(c.fi, mf);

  return mf;
}
int main() {
  ll maxflow = 0;
  while (ll plus = augment(s, t))
    maxflow += plus;
}
