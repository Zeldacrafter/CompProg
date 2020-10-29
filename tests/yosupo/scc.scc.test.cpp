#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../code/graphs/scc.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  adj.assign(n, vi());
  F0R(i, m) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
  }

  vvi comp = scc();
  cout << SZ(comp) << endl;
  for(int i = SZ(comp) - 1; ~i; --i) {
      cout << SZ(comp[i]) << ' ';
      for(int x : comp[i])
          cout << x << ' ';
      cout << endl;
  }
}

