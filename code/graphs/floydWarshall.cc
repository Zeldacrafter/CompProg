#include "../template.hh"
const ll INF = 1e18;
vector<vector<ll>> adj;  // adjacency matrix
bool negCycle = false;
void floydWarshall() {
  F0R (k, SZ(adj)) F0R (i, SZ(adj)) F0R (j, SZ(adj))
    if(adj[i][k] != INF && adj[k][j] != INF)
      ckmin(adj[i][j], adj[i][k] + adj[k][j]);
  F0R (k, SZ(adj)) if(adj[k][k] < 0) negCycle = true;
}
