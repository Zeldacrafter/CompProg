#include "../template.cc"
const int inf = 1e9;
// vertex a, vertex b, distance
typedef tuple<int, int, int> iii;
void bellmanFord(vector<iii>& edges,
                 vi& dist, int V,
                 int start) {
  dist.assign(V, inf);
  dist[start] = 0;
  F0R (i, V - 1)
    for (iii a : edges)
      ckmin(dist[ge(a, 1)],
            dist[ge(a, 0)] + ge(a, 2));
}
