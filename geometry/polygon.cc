#include "geometry.cc"
bool inTriangle(pt a, pt b, pt c, pt p) {
  return abs(-abs(dir(a, b, c)) + abs(dir(a, b, p)) + abs(dir(a, p, c)) + abs(dir(p, b, c))) < EPS;
}
bool inPolygon(vector<pt>& poly, pt p) {
  int l = 1, r = SZ(poly) - 2;
  while (l < r) {
    int mid = (l + r) / 2;
    if (cw(poly[0], poly[mid], p)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return inTriangle(poly[0], poly[l], poly[l - 1], p);
}
double area(vector<pt> p) {
  double res = 0.0;
  F0R (i, SZ(p))
    res += cross(p[i], p[(i + 1) % SZ(p)]);
  return abs(res) / 2;
}
bool isConvex(vector<pt> p) {
  // Assume that p[0] = p[SZ(p) - 1]
  if (SZ(p) < 4) return false;
  bool isLeft = ccw(p[0], p[1], p[2]);
  F0R (i, SZ(p) - 1)
    if (ccw(p[i], p[i + 1], p[(i + 2 == SZ(p)) ? 1 : i + 2]) !=
        isLeft)
      return false;
  return true;
}
