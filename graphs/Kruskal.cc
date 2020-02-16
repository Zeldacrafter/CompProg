#include "../template.cc"
// node a, node b, distance from a to b
typedef tuple<int, int, double> iid;
class unionFind {
 public:
  unionFind(int);
  void join(int, int);
  int find(int);
};
double kruskal(vector<iid>& edges, int V,
               vi& mst) {
  sort(ALL(edges),
       [](iid& a, iid& b) -> bool {
         return ge(a, 2) < ge(b, 2);
       });
  unionFind uf(V);
  double weigth = 0;
  for (int i = 0; SZ(uf) > 1; ++i) {
    int a = uf.find(ge(edges[i], 0));
    int b = uf.find(ge(edges[i], 1));
    if (a != b) {
      uf.join(a, b);
      mst.pb(i);
      weigth += ge(edges[i], 2);
    }
  }
  return weigth;
}
