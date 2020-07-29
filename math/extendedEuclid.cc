#include "../template.cc"
ll gcd(ll x, ll y, ll& a, ll& b) {
  if (y) {
    ll res = gcd(y, x % y, b, a);
    return b -= x / y * a, res; 
  }
  return a = 1, b = 0, x;
}
int main() {
  ll x, y;
  while (cin >> x >> y, ~x) {
    ll a, b;
    ll res = gcd(x, y, a, b);
    cout << dvar(res) << dvar(a) << dvar(b) << endl;
  }
}
