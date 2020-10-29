#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../code/graphs/pushRelabel.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E;
  cin >> V >> E;

  adj.resize(V);

  F0R(i, E) {
      int u, v, c;
      cin >> u >> v >> c;
      addEdge(u, v, c);
  }

  cout << maxflow(0, V - 1) << endl;
}



