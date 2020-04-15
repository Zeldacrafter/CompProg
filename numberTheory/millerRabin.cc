#include "../template.cc" // Taken from https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/MillerRabin.h
typedef long double ld;
typedef unsigned long long ull;
bool isPrime(ull n) {
  if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 1;
  ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  ull s = __builtin_ctzll(n - 1), d = n >> s;
  for (ull a : A) {
    ull p = modpow(a, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
      p = modmul(p, p, n);
    if (p != n - 1 && i != s) return false;
  }
  return true;
}

ull modmul(ull a, ull b, ull M) {
  ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
  return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
  ull ans = 1;
  for (; e; b = mod_mul(b, b, mod), e /= 2)
    if (e & 1) ans = mod_mul(ans, b, mod);
  return ans;
}
