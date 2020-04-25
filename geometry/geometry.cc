#include "../template.cc"
typedef complex<int> ci;
struct Line {
  double a, b, c;
};  // ax + by + c = 0

double inline dist(ci a, ci b) { return abs(a - b); }

// Theta in radiens
ci inline rotate(ci a, double theta) { return a * polar(1.0, theta); }

Line ptToLine(ci p1, ci p2) {
  if (abs(real(p1) - real(p2)) < EPS) {
    return {1.0, 0.0, -real(p1)};
  } else {
    int a = -(imag(p1) - imag(p2)) / (real(p1) - real(p2));
    int c = -(a * real(p1)) - imag(p2);
    return {a, 1.0, c};
  }
}

bool inline areParallel(Line l1, Line l2) {
  return abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS;
}

bool inline areSame(Line l1, Line l2) {
  return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;
}

ci intersectPt(Line l1, Line l2) {
  // Does not handle if same or parrallel
  if (areParallel(l1, l2)) return ci(-INFINITY, -INFINITY);
  double x =
      (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  double y;
  if (abs(l1.b) < EPS)
    y = -(l1.a * x + l1.c);
  else
    y = -(l2.a * x + l2.c);
  return ci(x, y);
}

double dot(ci a, ci b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// Shortest distance from p to line (a, b)
double distToLine(ci p, ci a, ci b) {
  ci ap = a - p;
  ci ab = a - b;
  double u = dot(ap, ab) / (abs(ab) * abs(ab));
  ci c = a + ab * u;  // This is our closest point
  return abs(p - c);
}

double distToLineSegment(ci p, ci a, ci b) {
  ci ap = a - p;
  ci ab = a - b;
  double u = dot(ap, ab) / (abs(ab) * abs(ab));
  if (u < 0.0) return abs(p - a);  // a is closest
  if (u > 1.0) return dist(p, b);  // b is closest
  return distToList(p, a, b);      // closest is in segment.
}

// Angle between a and b with o as origin.
// Return value in [0, 2PI)
double angle(ci a, ci b, ci o) {
  ci ao = a - o;
  ci bo = b - o;
  double angle =
      atan2(imag(bo), real(bo)) - atan2(imag(ao), real(ao));
  if (angle < 0) angle += 2 * M_PI;
  return angle;
}

double cross(ci a, ci b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

double dir(ci p, ci q, ci r) {
  return real(p) * (imag(q) - imag(r)) +
         real(q) * (imag(r) - imag(p)) +
         real(r) * (imag(p) - imag(q));
}

bool ccw(ci p, ci q, ci r) { return dir(p, q, r) > 0; }

bool cw(ci p, ci q, ci r) { return dir(p, q, r) < 0; }

bool collinear(ci p, ci q, ci r) { return abs(dir(p, q, r)) < EPS }
