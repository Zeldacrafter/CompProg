
#include "flowedge.cc"
template <typename F = ll>
struct DC {
  vector<edge<F>> edges;
  vvi adj;
  vi dist, ptr;
  int S, T, N;
  DC(int n, int m = 0, int s = -1, int t = -1) {
    reset(n, m, s, t);
  }
  void buildMatchingEdges(int m) {
    F0R (i, N) add(S, i, 1);
    F0R (i, m) add(N + i, T, 1);
  }
  int add(int from, int to, F c = numeric_limits<F>::max(), F f = 0) {
    edges.eb(from, to, c, f);
    adj[from].pb(SZ(edges) - 1);
    adj[to].pb(SZ(edges) - 1);
    return SZ(edges) - 1;
  }
  int match(int from, int to) { return add(from, N + to, 1);}
  vii matching() {
    vii res; res.reserve(maxflow());
    for (const auto& e : edges)
      if (e.mflow == 1 and e.mfrom != S and e.mto != T)
        res.eb(e.mfrom, e.mto);
    return res;
  }
  void clear() { edges.clear(); adj.clear(); }
  void reset(int n, int m = 0, int s = -1, int t = -1) {
    clear();
    adj.resize((N = n) + m + (s == -1) + (t == -1));
    S = s == -1 ? n + m : s;
    T = t == -1 ? n + m + (s == -1) : t;
    if (m != 0) buildMatchingEdges(m);
  }
  bool bfs(int s, int t) {
    dist.assign(SZ(adj), SZ(adj));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (SZ(q)) {
      int v = q.front(); q.pop();
      for (int i : adj[v]) {
        auto& e = edges[i];
        if (dist[e.other(v)] == SZ(adj) && e.flow(v) < e.capacity(v)) {
          dist[e.other(v)] = dist[v] + 1;
          q.push(e.other(v));
        }
      }
    }
    return dist[t] < SZ(adj);
  }
  F dfs(int v, int t, F available) {
    if (v == t || !available) return available;
    F pushed = 0;
    for (; ptr[v] < SZ(adj[v]); ++ptr[v]) {
      auto& e = edges[adj[v][ptr[v]]];
      if (dist[v] + 1 != dist[e.other(v)])
        continue;
      F wasPushed = dfs(e.other(v), t,
                        min(available - pushed, e.capacity(v) - e.flow(v)));
      pushed += wasPushed;
      e.adjust(v, wasPushed);
      if (pushed == available) return pushed;
    }
    return pushed;
  }
  F maxflow() {
    return maxflow(S, T);
  }
  F maxflow(int s, int t) {
    F f = 0;
    for (;;) {
      if (!bfs(s, t)) return f;
      ptr.assign(SZ(adj), 0);
      f += dfs(s, t, numeric_limits<F>::max());
    }
  }
};
using BM = DC<int>;
