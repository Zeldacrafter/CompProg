#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../dataStructures/FT.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  FT<ll> ft(n);

  F0R(i, n) {
    ll k;
    cin >> k;
    ft.update(i + 1, k);
  }

  while(q--) {
    bool c;
    int l, r;
    cin >> c >> l >> r;
    if(!c)
      ft.update(l + 1, r);
    else
      cout << ft.query(l + 1, r) << endl;
  }
}


