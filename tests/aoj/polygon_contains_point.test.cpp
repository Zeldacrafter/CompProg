#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

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

  pts.pb(pts[0]);
  reverse(ALL(pts));

  int q;
  cin >> q;
  while(q--) {
      int x, y;
      cin >> x >> y;
      pt p(x, y);

      bool onSegment = false;
      F0R(i, SZ(pts))
        onSegment |= distToLine(p, pts[i], pts[(i + 1) % SZ(pts)], true) < EPS;

      if(onSegment)
        cout << 1 << endl;
      else if(inPolygon(pts, p))
        cout << 2 << endl;
      else 
        cout << 0 << endl;
  }
}


