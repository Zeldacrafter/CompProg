#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../code/graphs/LCA.cc"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q; cin >> n >> q;

    vvi adj(n);
    FOR (i, 1, n) {
        int u; cin >> u;
        adj[i].pb(u);
        adj[u].pb(i);
    }

    LCA lca(adj);
    while(q--) {
        int u, v; cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }
}
