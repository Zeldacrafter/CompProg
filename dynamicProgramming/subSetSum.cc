#include "../template.cc"
const int mxSum = 1000;
bitset<mxSum + 1> subSetSum(const vi& v) {
  bitset<mxSum + 1> dp;
  dp[0] = 1;
  for (int i : v) dp |= dp << i;
  return dp;
}
