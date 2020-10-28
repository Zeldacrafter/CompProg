#include "../template.hh"
const int inf = 1e9;

int LIS(const vi& a) {
  vi dp(SZ(a) + 1, inf);
  dp[0] = -inf;
  F0R(i, SZ(a)) {
    int ind = upper_bound(ALL(dp), a[i]) - dp.begin();
    if(dp[ind - 1] < a[i] && a[i] < dp[ind])
      dp[ind] = a[i];
  }
  return lower_bound(ALL(dp), inf) - dp.begin() - 1;
}
