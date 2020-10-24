#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../dataStructures/SPT.cc"

const int INF = 1e9 + 5;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vi a(n);
  F0R(i, n)
    cin >> a[i];

  SPT spt(a);
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << spt.rmq(l, r).fi << endl;
  }
}




