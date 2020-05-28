#include "../dataStructures/DSU.cc"
// re if graph is not connected
vector<tuple<double, int, int>> edges;
int V;
pair<double, vi> kruskal() {
  sort(ALL(edges)); DSU dsu(V); vi mst;
  double weigth = 0;
  for (int i = 0; SZ(dsu) > 1; ++i) {
    auto [d, a, b] = edges[i];
    if (dsu.join(a, b)) mst.pb(i), weigth += d;
  }
  return mp(weigth, mst);
}
