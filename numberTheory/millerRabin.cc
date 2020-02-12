#include "../template.cc"
bool checkComp(ll n, ll a, ll d, int s) {
  ll x = modpow(a, d, n);
  if (x == 1 || x == n - 1) return false;
  FOR (r, 1, s) {
    x = (__int128)x * x % n;
    if (x == n - 1) return false;
  }
  return true;
};

bool isPrime(ll n, int iter = 10) {
  if (n < 4) return n == 2 || n == 3;

  int s = 0;
  ll d = n - 1;
  while (!(d & 1)) {
    d >>= 1;
    s++;
  }

  F0R (i, iter)
    if (checkComp(n, 2 + rand() % (n - 3), d,
                  s))
      return false;
  return true;
}
