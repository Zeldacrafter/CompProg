#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../code/graphs/bridges.cc"

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

  vii res = findBridges();
  for(auto& [a, b] : res) if(a > b) swap(a, b);
  sort(ALL(res));
  for(auto [a, b] : res)
      cout << a << ' ' << b << endl;
}





