#include "../template.cc"
ll C(int n, int k) {
  double res = 1;
  ckmin(k, n - k);
  FOR (i, 1, k + 1)
    res = res * (n - k + i) / i;
  return (ll)(res + 0.01);
}
