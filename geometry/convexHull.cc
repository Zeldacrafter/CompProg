void convexHull(vector<ci>& pts) {
  // Assume that pts[0] != pts[SZ(pts) - 1]
  if (!SZ(pts)) return;
  sort(ALL(pts),
       [](const ci& a, const ci& b) {
         if (real(a) != real(b))
           return real(a) < real(b);
         else
           return imag(a) < imag(b);
       });

  ci fst = pts[0];
  ci lst = pts[SZ(pts) - 1];
  vector<ci> up, down;
  up.pb(fst);
  down.pb(fst);

  for (ci p : pts) {
    if (p == lst || cw(fst, p, lst)) {
      while (SZ(up) >= 2 &&
             !cw(up[SZ(up) - 2],
                 up[SZ(up) - 1], p))
        up.pop_back();
      up.pb(p);
    }
    if (p == lst || ccw(fst, p, lst)) {
      while (SZ(down) >= 2 &&
             !ccw(down[SZ(down) - 2],
                  down[SZ(down) - 1], p))
        down.pop_back();
      down.pb(p);
    }
  }

  pts = vector<ci>(down);
  R0F (i, SZ(up) - 2)
    pts.pb(up[i]);
}
