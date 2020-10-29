#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../code/graphs/bellmanFord.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int E, r;
  cin >> V >> E >> r;

  edges.resize(E);

  F0R(i, E) {
      int u, v, d;
      cin >> u >> v >> d;
      edges.eb(v, u, d);
  }

  auto [negCycle, res] = bellmanFord(r);
  if(negCycle) {
      cout << "NEGATIVE CYCLE\n";
  } else {
      for(int d : res) {
          if(d == inf)
              cout << "INF\n";
          else
              cout << d << endl;
      }
  }
}




