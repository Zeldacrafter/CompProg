#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../code/graphs/dinic.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E;
  cin >> V >> E;

  DC d(V, 0, 0, V - 1);

  F0R(i, E) {
      int u, v, c;
      cin >> u >> v >> c;
      d.add(u, v, c);
  }

  cout << d.maxflow() << endl;
}


