#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "../../code/template.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--) {
    ll a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
}
