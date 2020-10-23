#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../dataStructures/DSU.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  
  int n, q;
  cin >> n >> q;
  
  DSU dsu(n);
  while(q--) {
    int a, b ,c;
    cin >> a >> b >> c;
    if(!a) {
      dsu.join(b, c);
    } else {
      cout << dsu.sameSet(b, c) << endl;
    }
  }
}
