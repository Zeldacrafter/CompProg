#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include "../../code/dynamicProgramming/editDistance.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string s1, s2;
  cin >> s1 >> s2;
  cout << editDistance(s1, s2) << endl;
}


