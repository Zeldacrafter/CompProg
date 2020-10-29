#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../code/math/extendedEuclid.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  ll a, b, x, y;
  cin >> a >> b;
  gcd(a, b, x, y);
  cout << x << ' ' << y << endl;
}
