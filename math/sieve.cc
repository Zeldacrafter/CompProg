#include "../template.cc"
const int N = 1e7;
int lp[N + 1];
void sieve() {
  vi pr;
  FOR (i, 2, N + 1) {
    if (!lp[i]) {
      lp[i] = i;
      pr.pb(i);
    }
    for (int j = 0; j < SZ(pr) && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
