#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include "../../code/geometry/geometry.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  double x0, y0, x1, y1;
  int q;
  cin >> x0 >> y0 >> x1 >> y1 >> q;
  pt p0(x0, y0), p1(x1, y1);

  while(q--) {
    int x2, y2;
    cin >> x2 >> y2;
    pt p2(x2, y2);

    if(ccw(p0, p1, p2))
        cout << "COUNTER_CLOCKWISE\n";
    else if(cw(p0, p1, p2))
        cout << "CLOCKWISE\n";
    else if(abs(p0 - p2) < EPS || abs(p1 - p2) < EPS || (abs(p0 - p2) < abs(p0 - p1) && abs(p1 - p2) < abs(p1 - p0)))
        cout << "ON_SEGMENT\n";
    else if(abs(p1 - p2) > abs(p0 - p1) && abs(p1 - p2) > abs(p0 - p2))
        cout << "ONLINE_BACK\n";
    else
        cout << "ONLINE_FRONT\n";
  }
}
