#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#define ERROR 0.000001

#include "../../code/geometry/polygon.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pt> pts(n);
  F0R(i, n) {
      int x, y;
      cin >> x >> y;
      pts[i] = pt(x, y);
  }
  cout << fixed << setprecision(6) << area(pts) << endl;
}

