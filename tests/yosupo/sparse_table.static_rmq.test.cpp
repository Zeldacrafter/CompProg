#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../code/dataStructures/SPT.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  auto f = [](int a, int b) { return min(a, b); };
  SPT<int, decltype(f)> st(n, f);
  F0R(i, n) cin >> st.d[0][i];
  st.build();

  while(q--) {
    int l, r; cin >> l >> r;
    cout << st.query(l, r) << endl;
  }
}




