#include "../template.hh"
ll onEdge(vii pts) { // Assume pts[0] = pts[SZ(pts) - 1]
  ll res = SZ(pts);
  F0R (i, SZ(pts) - 1)
    res += abs(gcd(pts[i].fi - pts[i + 1].fi, pts[i].se - pts[i + 1].se));
  return res;
}
