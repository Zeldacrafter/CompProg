#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include "../../code/graphs/HLD.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  vvi adj(n);
  F0R(i, n) {
      int k;
      cin >> k;
      F0R(j, k) {
          int c;
          cin >> c;
          adj[i].pb(c);
          adj[c].pb(i);
      }
  }
  
  auto f = [](int a, int b) { return a + b; };
  HLD<int, decltype(f)> hld(adj, vi(n), 0, f);
  
  int q;
  cin >> q;
  while(q--) {
    bool b;
    cin >> b;
    if(!b) {
      int v, w;
      cin >> v >> w;
      int curr = hld.queryPath(v, v);
      hld.update(v, w + curr);
    } else {
      int u;
      cin >> u;
      cout << hld.queryPath(0, u) << endl;
    }
  }
}





