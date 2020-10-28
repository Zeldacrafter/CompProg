#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../code/strings/SA.cc"

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  SA sa(s);
  FOR (i, 1, SZ(sa.sa)) cout << sa.sa[i] << ' ';
  cout << endl;
}
