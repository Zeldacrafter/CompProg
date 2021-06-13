#include "../dataStructures/DSU.cc"
template <typename W, typename C = less<tuple<W, int, int>>>
tuple<bool, W, vi> kruskal(int V, vector<tuple<W, int, int>>& edges, C cmp = C()) {
  sort(ALL(edges), cmp); DSU dsu(V); vi mst;
  W w = 0;
  for (int i = 0; SZ(dsu) > 1 && i < SZ(edges); ++i) {
    auto [d, a, b] = edges[i];
    if (dsu.join(a, b)) mst.pb(i), w += d;
  }
  return mt(SZ(dsu) == 1, w, mst);
}
