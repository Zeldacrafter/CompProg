#include "../template.hh"
const int inf = 1e9;
// vertex a, vertex b, distance
vector<tuple<int, int, int>> edges;
int V;
// Returns empty vector on negative cycle
vi bellmanFord(int start) {
  vi dist(V, inf);
  dist[start] = 0;
  bool negCycle = false;
  F0R (i, V) {
    negCycle = false;
    for (auto [a, b, d] : edges)
      if (dist[a] < inf && ckmin(dist[b], dist[a] + d))
          negCycle = true;
  }
  return negCycle ? vi() : dist;
}
