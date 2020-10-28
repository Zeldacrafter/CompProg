#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../code/dataStructures/SPTI.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  auto f = [](int a, int b) { return a <= b; };
  SPTI<int, decltype(f)> st(n, f);
  F0R(i, n) cin >> st.d[i];
  st.build();

  while(q--) {
    int l, r; cin >> l >> r;
    cout << st.d[st.query(l, r)] << endl;
  }
}




