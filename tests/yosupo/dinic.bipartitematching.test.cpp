#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../code/graphs/dinic.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int l, r, m;
  cin >> l >> r >> m;

  BM bm(l, r);

  F0R(i, m) {
      int u, v;
      cin >> u >> v;
      bm.match(u, v);
  }

  vii matching = bm.matching();
  cout << SZ(matching) << endl;
  for (auto [u, v] : matching) {
    cout << u << ' ' << v << endl;
  }
}

