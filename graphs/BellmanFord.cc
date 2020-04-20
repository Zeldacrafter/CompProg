#include "../template.cc"
const int inf = 1e9;
// vertex a, vertex b, distance
typedef tuple<int, int, int> iii;
void bellmanFord(vector<iii>& edges, vi& dist, int V, int start) {
  dist.assign(V, inf);
  dist[start] = 0;
  F0R (i, V - 1)
    for (iii a : edges)
      ckmin(dist[get<1>(a)], dist[get<0>(a)] + get<2>(a));
}
