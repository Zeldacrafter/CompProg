bool inPolygon(vector<ci> pts, ci p) {
  // Assume that pts[0] = pts[SZ(pts) - 1]
  if (!SZ(pts)) return false;
  double sum = 0.0;
  F0R (i, SZ(pts) - 1) {
    if (ccw(p, pts[i], pts[i + 1]) ||
        collinear(p, pts[i], pts[i + 1]))
      sum += angle(pts[i], p, pts[i + 1]);
    else
      sum += angle(pts[i + 1], p, pts[i]);
  }
  return abs(abs(sum) - 2 * M_PI) < EPS;
}

double area(vector<ci> p) {
  // Assume that p[0] = p[SZ(p) - 1]
  double res = 0.0;
  F0R (i, SZ(p) - 1)
    res += real(p[i]) * imag(p[i + 1]) -
           imag(p[i]) * real(p[i + 1]);
  return abs(res) / 2;
}

bool isConvex(vector<ci> p) {
  // Assume that p[0] = p[SZ(p) - 1]
  if (SZ(p) < 4) return false;
  bool isLeft = ccw(p[0], p[1], p[2]);
  F0R (i, SZ(p) - 1)
    if (ccw(p[i], p[i + 1],
            p[(i + 2 == SZ(p)) ? 1
                               : i + 2]) !=
        isLeft)
      return false;
  return true;
}
