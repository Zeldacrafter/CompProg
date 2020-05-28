#include "../template.cc"
vvi adj; // adjacency matrix
void floydWarshall() {
  F0R (k, SZ(adj)) F0R (i, SZ(adj)) F0R (j, SZ(adj))
    ckmin(adj[i][j], adj[i][k] + adj[k][j]);
}
