#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../../code/graphs/articulationPoints.cc"
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E;
  cin >> V >> E;

  adj.resize(V);

  F0R(i, E) {
      int u, v;
      cin >> u >> v;
      adj[u].eb(v);
      adj[v].eb(u);
  }

  vi res = findArtiPoints();
  sort(ALL(res));
  for(int i : res)
      cout << i << endl;
}




