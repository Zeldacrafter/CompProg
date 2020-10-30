#include "geometry.cc"
bool inTriangle(pt a, pt b, pt c, pt p) {
  return
    abs(-abs(dir(a, b, c)) + abs(dir(a, b, p))
        + abs(dir(a, p, c)) + abs(dir(p, b, c))) < EPS;
}
// poly sorted in clockwise direction.
// poly[0] = poly[SZ(poly) - 1]
// returns true if point is on edge of poly.
bool inPolygon(const vector<pt>& poly, pt p) {
  int l = 1, r = SZ(poly) - 2;
  while (l < r) {
    int mid = (l + r) / 2;
    if (cw(poly[0], poly[mid], p))
      l = mid + 1;
    else
      r = mid;
  }
  return inTriangle(poly[0], poly[l], poly[l - 1], p);
}
double area(const vector<pt>& p) {
  double res = 0.0;
  F0R (i, SZ(p))
    res += cross(p[i], p[(i + 1) % SZ(p)]);
  return abs(res) / 2;
}
bool isConvex(const vector<pt>& p) {
  if (SZ(p) < 3) return false;
  bool isLeft = ccw(p[0], p[1], p[2]) || collinear(p[0], p[1], p[2]),
      convex = true;
  F0R (i, SZ(p))
    convex &= isLeft == (ccw(p[i], p[(i + 1) % SZ(p)], p[(i + 2) % SZ(p)])
                     || collinear(p[i], p[(i + 1) % SZ(p)], p[(i + 2) % SZ(p)]));
  return convex;
}
