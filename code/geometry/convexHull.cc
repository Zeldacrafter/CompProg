#include "geometry.cc"
// careful with inputs for n < 2
vector<pt> convexHull(vector<pt>& pts) {
  int n = SZ(pts);
  sort(ALL(pts),
       [](pt a, pt b) { return mp(a.xx, a.yy) < mp(b.xx, b.yy); });
  vector<pt> up, down;
  up.eb(pts[0]); down.eb(pts[0]);
  FOR (i, 1, n) {
    // for colinear poins change ccw->!cw & cw->!ccw
    if (i == n - 1 || ccw(pts[0], pts[n - 1], pts[i])) {
      while (SZ(up) > 1 &&
             ccw(up[SZ(up) - 2], up[SZ(up) - 1], pts[i]))
        up.pop_back();
      up.eb(pts[i]);
    }
    if (i == n - 1 || cw(pts[0], pts[n - 1], pts[i])) {
      while (SZ(down) > 1 &&
             cw(down[SZ(down) - 2], down[SZ(down) - 1], pts[i]))
        down.pop_back();
      down.eb(pts[i]);
    }
  }
  vector<pt> ans(up);
  ans.insert(ans.end(), 1 + RALL(down));
  return ans;
}
