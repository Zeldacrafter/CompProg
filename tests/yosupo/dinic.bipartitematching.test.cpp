#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../code/graphs/dinic.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int l, r, m;
  cin >> l >> r >> m;

  int source = l + r, target = l + r + 1;
  adj.resize(l + r + 2);

  F0R(i, l) addEdge(source, i, 1);
  F0R(i, r) addEdge(l + i, target, 1);

  F0R(i, m) {
      int u, v;
      cin >> u >> v;
      addEdge(u, l + v, 1);
  }

  cout << maxflow(source, target) << endl;
  for(edge& e : edges)
    if(e.mfrom != source && e.mto != target && e.mflow == 1)
        cout << e.mfrom << ' ' << e.mto - l << endl;
}

