#include "../dataStructures/DSU.cc"
// node a, node b, distance from a to b
typedef tuple<int, int, double> iid;
double kruskal(vector<iid>& edges, int V, vi& mst) {
  sort(ALL(edges),
       [](iid& a, iid& b) -> bool { return get<2>(a) < get<2>(b); });
  DSU dsu(V);
  double weigth = 0;
  for (int i = 0; SZ(dsu) > 1; ++i) {
    if (dsu.join(get<0>(edges[i]), get<1>(edges[i]))) {
      mst.pb(i);
      weigth += get<2>(edges[i]);
    }
  }
  return weigth;
}
