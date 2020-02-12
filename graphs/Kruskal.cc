#include "../template.cc"
// node a, node b, distance from a to b
typedef tuple<int, int, double> iid;
class unionFind;
int main() {
  vector<iid> edges;
  sort(ALL(edges),
       [](iid& a, iid& b) -> bool {
         return get<2>(a) < get<2>(b);
       });
  unionFind uf(V);
  double weigth = 0;
  vi mst;
  for (int i = 0; SZ(uf) != 1; ++i) {
    int a = uf.find(get<0>(edges[i]));
    int b = uf.find(get<1>(edges[i]));
    if (a != b) {
      uf.join(a, b);
      mst.pb(i);
      weigth += get<2>(edges[i]);
    }
  }
}
