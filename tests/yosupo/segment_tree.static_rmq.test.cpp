#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../dataStructures/STIT.cc"

const int INF = 1e9 + 5;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  ST<int> st(n, INF, [](auto a, auto b) { return min(a, b); });

  F0R(i, n)
    cin >> st.data[n + i];
  st.build();

  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r) << endl;
  }
}



