#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../code/dataStructures/STIT.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  auto f = [](auto a, auto b) { return a + b; };
  ST<ll, decltype(f)> st(n, 0, f);

  F0R(i, n)
    cin >> st.data[n + i];
  st.build();

  while(q--) {
    bool c;
    int l, r;
    cin >> c >> l >> r;
    if(!c)
      st.update(l, st.query(l, l + 1) + r);
    else
      cout << st.query(l, r) << endl;
  }
}



