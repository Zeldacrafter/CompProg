#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include "../../code/dynamicProgramming/tsp.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N, E;
  cin >> N >> E;

  adj.assign(N, vi(N, INF));
  F0R(i, E) {
      int s, t, d;
      cin >> s >> t >> d;
      adj[s][t] = d;
  }

  int res = tsp();
  cout << (res == INF ? -1 : res) << endl;
}
