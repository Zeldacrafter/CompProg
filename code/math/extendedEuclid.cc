#include "../template.hh"
ll gcd(ll x, ll y, ll& a, ll& b) {
  if (y) {
    ll res = gcd(y, x % y, b, a);
    return b -= x / y * a, res; 
  }
  return a = 1, b = 0, x;
}
