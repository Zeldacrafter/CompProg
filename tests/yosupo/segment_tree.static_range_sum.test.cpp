#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../dataStructures/STIT.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  ST<ll> st(n, 0, [](auto a, auto b) { return a + b; });

  F0R(i, n)
    cin >> st.data[n + i];
  st.build();

  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r) << endl;
  }
}


