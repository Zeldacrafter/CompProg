
#include "flowedge.cc"
template <typename F = ll>
struct EK {
  vvi adj;
  vector<edge<F>> edges;
  int S, T;
  EK(int n, int s = -1, int t = -1) { reset(n, s, t); }
  int add(int from, int to, F c = numeric_limits<F>::max(), F f = 0) {
    edges.eb(from, to, c, f);
    adj[from].pb(SZ(edges) - 1);
    adj[to].pb(SZ(edges) - 1);
    return SZ(edges) - 1;
  }
  void clear() { edges.clear(); adj.clear(); }
  void reset(int n, int s = -1, int t = -1) {
    clear();
    adj.resize(n + (s == -1) + (t == -1));
    S = s == -1 ? n : s;
    T = t == -1 ? n + (s == -1) : t;
  }
  F augment(int s, int t) {
    vii p(SZ(adj), {-1, -1});
    queue<int> q;
    p[s] = mp(-1, 0);
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      if (v == t) break;
      q.pop();
      for (int i : adj[v]) {
        auto& e = edges[i];
        if (p[e.other(v)].se == -1 && e.flow(v) < e.capacity(v)) {
          p[e.other(v)] = mp(v, i); q.push(e.other(v));
        }
      }
    }
    if (p[t].se == -1) return 0;
    F mf = numeric_limits<F>::max();
    for (ii c = p[t]; c.fi != -1; c = p[c.fi])
      ckmin(mf, edges[c.se].capacity(c.fi) - edges[c.se].flow(c.fi));
    for (ii c = p[t]; c.fi != -1; c = p[c.fi])
      edges[c.se].adjust(c.fi, mf);
    return mf;
  }
  F maxflow() { return maxflow(S, T); }
  F maxflow(int s, int t) {
    F maxflow = 0;
    while (F plus = augment(s, t)) maxflow += plus;
    return maxflow;
  }
};

