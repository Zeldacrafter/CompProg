#include "../template.cc"
const int inf = 1e9;
int knapsack(const vi& w, const vi& p, int B) {
  ll maxP = accumulate(ALL(p), 0);

  vvi dp(maxP + 1, vi(SZ(w), inf));
  fill(ALL(dp[0]), 0);
  dp[p[0]][0] = w[0];

  FOR(t, 1, maxP + 1) {
    FOR(i, 1, SZ(w)) {
      dp[t][i] = dp[t][i - 1];
      if(t - p[i] >= 0)
        ckmin(dp[t][i], dp[t - p[i]][i - 1] + w[i]);
    }
  }

  int res = 0;
  F0R(i, maxP + 1)
    if(dp[i][SZ(w) - 1] <= B)
      ckmax(res, i);
  return res;
}
