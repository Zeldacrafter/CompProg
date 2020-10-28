#include "../template.hh"
const int inf = 1e9;

int editDistance(const string& a, const string& b) {
  vvi dp(SZ(a) + 1, vi(SZ(b) + 1, inf));
  F0R(i, SZ(a) + 1) {
    F0R(j, SZ(b) + 1) {
      if(!i) dp[i][j] = j;
      else if(!j) dp[i][j] = i;
      else {
        dp[i][j] = 1 + min({dp[i - 1][j - 1],
                            dp[i][j - 1], dp[i - 1][j]});
        if(a[i - 1] == b[j - 1]) ckmin(dp[i][j], dp[i - 1][j - 1]);
      }
    }
  }
  return dp[SZ(a)][SZ(b)];
}
