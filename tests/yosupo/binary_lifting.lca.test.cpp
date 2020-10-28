#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../code/graphs/LCABL.cc"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vvi adj(n);
    F0R(i, n - 1) {
        int u;
        cin >> u;
        adj[i + 1].pb(u);
        adj[u].pb(i + 1);
    }
    
    LCA lca(adj);
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}

