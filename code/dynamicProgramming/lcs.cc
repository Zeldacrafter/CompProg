#include "../template.cc"
int lcs(const string& s, const string& t) {
  int n = SZ(s), m = SZ(t);
  vvi dp(n + 1, vi(m + 1, 0));
  dp[n - 1][m - 1] = s[n - 1] == t[m - 1];
  for (int i = n - 2; ~i; --i)
    dp[i][m - 1] = s[i] == t[m - 1] ? 1 : dp[i + 1][m - 1];
  for (int i = m - 2; ~i; --i)
    dp[n - 1][i] = s[n - 1] == t[i] ? 1 : dp[n - 1][i + 1];
  for (int i = n - 2; ~i; --i)
    for (int j = m - 2; ~j; --j)
      dp[i][j] = max({dp[i + 1][j + 1] + (s[i] == t[j]),
                      dp[i + 1][j], dp[i][j + 1]});
  return dp[0][0];
}
