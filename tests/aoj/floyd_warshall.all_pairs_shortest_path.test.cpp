#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include "../../code/graphs/floydWarshall.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int V, E;
  cin >> V >> E;

  adj.assign(V, vector<ll>(V, INF));

  F0R(i, E) {
      int u, v, d;
      cin >> u >> v >> d;
      ckmin(adj[u][v], (ll)d);
  }

  F0R(i, V) adj[i][i] = 0;
  floydWarshall();

  if(negCycle) {
      cout << "NEGATIVE CYCLE\n";
  } else {
      F0R(i, V) {
        F0R(j, V) {
          if(j) cout << ' ';
          if(adj[i][j] == INF)
            cout << "INF";
          else
            cout << adj[i][j];
        }
        cout << endl;
      }
  }
}





