#include "../template.hh"
const int INF = 1e9;
vvi dp, adj; // adjacency matrix
int tsp_calc(int pos, int start, int mask) {
  if ((1 << SZ(adj)) - 1 == mask) return adj[pos][start];
  if (dp[pos][mask] != -1) return dp[pos][mask];
  int minV = INF;
  F0R (i, SZ(adj))
    if (i != pos && !(mask & (1 << i)))
      ckmin(minV, adj[pos][i] + tsp_calc(i, start, mask | (1 << i)));
  return dp[pos][mask] = minV;
}
int tsp(int start = 0) {
  dp.assign(SZ(adj), vi(1 << SZ(adj), -1));
  F0R(i, SZ(adj)) ckmin(adj[i][i], 0);
  return tsp_calc(start, start, 1 << start);
}
