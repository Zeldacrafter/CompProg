#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include "../../code/dynamicProgramming/lis.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  F0R(i, n) cin >> a[i];

  cout << lis(a) << endl;
}


