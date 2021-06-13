#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../code/graphs/dijkstra.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E, r;
  cin >> V >> E >> r;

  vvii adj(V);

  F0R(i, E) {
      int u, v, d;
      cin >> u >> v >> d;
      adj[u].eb(v, d);
  }

  const int inf = 1e9;
  vi res = dijkstra(r, adj);
  for(int d : res) {
      if(d == inf)
          cout << "INF\n";
      else
          cout << d << endl;
  }
}



