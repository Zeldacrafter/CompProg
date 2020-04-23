#include "../template.cc"
const ll inf = 10e12;
// initialize non existing edges w/ 0
// initialize residual edges w/ maxf =
// currentf where the value is the maxf value
// from the corresponding edge.
const int V = 500;  // number of nodes;
ll maxf[V][V];
ll currentf[V][V];
ll augment(const ll s, const ll t) {
  vi p(t + 1, -1);
  queue<ll> q;
  p[s] = s;
  q.push(s);
  while (!q.empty()) {
    ll v = q.front();
    if (v == t) break;
    q.pop();
    F0R (u, V) {  // maybe needs adjustment if V is not constant
      if (p[u] == -1 && currentf[v][u] < maxf[v][u]) {
        p[u] = v;
        q.push(u);
      }
    }
  }
  if (p[t] == -1) return 0;
  ll mf = inf;
  for (ll c = t; c != s; c = p[c])
    ckmin(mf, maxf[p[c]][c] - currentf[p[c]][c]);
  for (ll c = t; c != s; c = p[c])
    currentf[p[c]][c] += mf, currentf[c][p[c]] -= mf;
  return mf;
}
ll maxflow(int s, int t) {
  ll maxflow = 0;
  while (ll plus = augment(s, t)) maxflow += plus;
  return maxflow;
}
