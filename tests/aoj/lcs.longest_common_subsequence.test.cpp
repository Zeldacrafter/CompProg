#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include "../../code/dynamicProgramming/lcs.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int tc;
  cin >> tc;
  while(tc--) {
      string s1, s2;
      cin >> s1 >> s2;
      cout << lcs(s1, s2) << endl;
  }
}

