#include "../template.cc"
const int inf = 1e9;
// vertex a, vertex b, distance
vector<tuple<int, int, int>> edges;
int V;
vi bellmanFord(int start) {
  vi dist(V, inf);
  dist[start] = 0;
  F0R (i, V - 1)
    for (auto [a, b, d] : edges)
      ckmin(dist[a], dist[b] + d);
  return dist;
}
