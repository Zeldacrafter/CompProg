#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../code/graphs/kruskal.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E;
  cin >> V >> E;
  vector<tuple<double, int, int>> edges;

  F0R(i, E) {
      int u, v;
      double w;
      cin >> u >> v >> w;
      edges.eb(w, u, v);
  }

  cout << (ll)get<1>(kruskal(V, edges)) << endl;
}

