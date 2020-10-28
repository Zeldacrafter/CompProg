
#include "flowedge.cc"
const ll inf = 10e16;
vi label;
vi currentEdge;
vector<ll> excess;
queue<int> active;
void push(int v, edge& e) {
  ll more = min(excess[v], e.capacity(v) - e.flow(v));
  excess[e.other(v)] += more;
  excess[v] -= more;
  e.adjust(v, more);
  if (more && excess[e.other(v)] == more) active.push(e.other(v));
}
void relabel(int v) {
  int m = numeric_limits<int>::max();
  for (int i : adj[v]) {
    auto& e = edges[i];
    if (e.flow(v) < e.capacity(v)) ckmin(m, label[edges[i].other(v)]);
  }
  if (m < numeric_limits<int>::max()) label[v] = m + 1;
}
void discharge(int v) {
  while (excess[v]) {
    auto& e = edges[adj[v][currentEdge[v]]];
    if (label[v] - 1 == label[e.other(v)] &&
        e.flow(v) < e.capacity(v))
      push(v, e);
    else if (SZ(adj[v]) == ++currentEdge[v]) {
      currentEdge[v] = 0;
      relabel(v);
    }
  }
}
ll maxflow(int s, int t) {
  currentEdge.assign(SZ(adj), 0);
  label.assign(SZ(adj), 0);
  excess.assign(SZ(adj), 0);
  excess[s] = inf;
  label[s] = SZ(adj);
  for (int i : adj[s]) push(s, edges[i]);
  while (!active.empty()) {
    if (active.front() != s && active.front() != t)
      discharge(active.front());
    active.pop();
  }
  ll maxflow = 0;
  for (int i : adj[s]) maxflow += edges[i].flow(s);
  return maxflow;
}
