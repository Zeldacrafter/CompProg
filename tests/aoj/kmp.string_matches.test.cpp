#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "../../code/strings/kmp.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string s, s2;
  cin >> s >> s2;

  vi res = match(s, s2);
  for(int i : res)
      cout << i << endl;
}



