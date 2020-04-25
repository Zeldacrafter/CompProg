#include "../dataStructures/unionFind.cc"
// node a, node b, distance from a to b
typedef tuple<int, int, double> iid;
double kruskal(vector<iid>& edges, int V, vi& mst) {
  sort(ALL(edges),
       [](iid& a, iid& b) -> bool { return get<2>(a) < get<2>(b); });
  unionFind uf(V);
  double weigth = 0;
  for (int i = 0; SZ(uf) > 1; ++i) {
    if (uf.join(get<0>(edges[i]), get<1>(edges[i]))) {
      mst.pb(i);
      weigth += get<2>(edges[i]);
    }
  }
  return weigth;
}
