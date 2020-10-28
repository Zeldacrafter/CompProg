#include "../dataStructures/DSU.cc"
vector<tuple<double, int, int>> edges;
int V; // bool indicates if MST could be found / graph is connected
tuple<bool, double, vi> kruskal() {
  sort(ALL(edges)); DSU dsu(V); vi mst;
  double weigth = 0;
  for (int i = 0; SZ(dsu) > 1 && i < SZ(edges); ++i) {
    auto [d, a, b] = edges[i];
    if (dsu.join(a, b)) mst.pb(i), weigth += d;
  }
  return mt(SZ(dsu) == 1, weigth, mst);
}
