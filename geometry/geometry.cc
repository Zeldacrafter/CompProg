#include "../template.cc"
#define xx real()
#define yy imag()
const double EPS = 1e-9;
const double INF = numeric_limits<double>::max();
using pt = complex<double>;
struct Line {
  double a, b, c;
};  // ax + by + c = 0
double dot(pt a, pt b) { return a.xx * b.xx + a.yy * b.yy; }
double cross(pt a, pt b) { return a.xx * b.yy - a.yy * b.xx; }
double dir(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool cw(pt a, pt b, pt c) { return dir(a, b, c) < 0; }
bool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }
bool collinear(pt a, pt b, pt c) { return abs(dir(a, b, c)) < EPS; }
// Angle between a and b with o as origin (ccw).
// Return value in [0, 2PI)
double angle(pt a, pt b) {
  double ang = arg(a) - arg(b);
  return ang < 0 ? ang + 2 * M_PI : ang;
}
double angle(pt a, pt b, pt o) { return angle(b - o, a - o); }
// Theta in radiens
pt rotate(pt a, double theta) { return a * polar(1.0, theta); }
Line ptToLine(pt p1, pt p2) {
  if (abs(real(p1) - real(p2)) < EPS) {
    return {1.0, 0.0, -real(p1)};
  } else {
    double a = -(imag(p1) - imag(p2)) / (real(p1) - real(p2)),
           c = -(a * real(p1)) - imag(p2);
    return {a, 1.0, c};
  }
}
bool areParallel(Line l1, Line l2) {
  return abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS;
}
bool areSame(Line l1, Line l2) {
  return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;
}
pt intersectPt(Line l1, Line l2) {
  // Does not handle if same or parrallel
  if (areParallel(l1, l2)) return pt(-INF, -INF);
  double x =
      (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  double y;
  if (abs(l1.b) < EPS)
    y = -(l1.a * x + l1.c);
  else
    y = -(l2.a * x + l2.c);
  return pt(x, y);
}
double distToLine(pt p, pt a, pt b, bool segment = false) {
  pt ap = p - a, ab = b - a;
  double u = dot(ap, ab) / (abs(ab) * abs(ab));
  if (segment) {
    if (u < 0.0) return abs(p - a);  // a is closest
    if (u > 1.0) return abs(p - b);  // b is closest
  }
  return abs(p - a - ab * u);      // closest is in segment.
}
