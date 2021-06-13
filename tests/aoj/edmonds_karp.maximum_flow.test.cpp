#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../code/graphs/edmondsKarp.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E;
  cin >> V >> E;

  EK ek(V, 0, V - 1);

  F0R(i, E) {
      int u, v, c;
      cin >> u >> v >> c;
      ek.add(u, v, c);
  }

  cout << ek.maxflow() << endl;
}



