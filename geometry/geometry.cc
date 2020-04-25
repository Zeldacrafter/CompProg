#include "../template.cc"
const double EPS = 1e-9;
const double INF = numeric_limits<double>::max();
typedef complex<double> cd;
typedef complex<int> ci;
struct Line {
  double a, b, c;
};  // ax + by + c = 0

template<class T>
double inline dist(complex<T> a, complex<T> b) { return abs(a - b); }

// Theta in radiens
cd inline rotate(cd a, double theta) { return a * polar(1.0, theta); }

Line ptToLine(cd p1, cd p2) {
  if (abs(real(p1) - real(p2)) < EPS) {
    return {1.0, 0.0, -real(p1)};
  } else {
    double a = -(imag(p1) - imag(p2)) / (real(p1) - real(p2)),
           c = -(a * real(p1)) - imag(p2);
    return {a, 1.0, c};
  }
}

bool inline areParallel(Line l1, Line l2) {
  return abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS;
}

bool inline areSame(Line l1, Line l2) {
  return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;
}

cd intersectPt(Line l1, Line l2) {
  // Does not handle if same or parrallel
  if (areParallel(l1, l2)) return cd(-INF, -INF);
  double x =
      (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  double y;
  if (abs(l1.b) < EPS)
    y = -(l1.a * x + l1.c);
  else
    y = -(l2.a * x + l2.c);
  return cd(x, y);
}

double dot(cd a, cd b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// Shortest distance from p to line (a, b)
double distToLine(cd p, cd a, cd b) {
  cd ap = a - p, ab = a - b;
  double u = dot(ap, ab) / (abs(ab) * abs(ab));
  cd c = a + ab * u;  // This is our closest point
  return abs(p - c);
}

double distToLineSegment(cd p, cd a, cd b) {
  cd ap = a - p, ab = a - b;
  double u = dot(ap, ab) / (abs(ab) * abs(ab));
  if (u < 0.0) return abs(p - a);  // a is closest
  if (u > 1.0) return dist(p, b);  // b is closest
  return distToLine(p, a, b);      // closest is in segment.
}

// Angle between a and b with o as origin.
// Return value in [0, 2PI)
template<class T>
double angle(complex<T> a, complex<T> b, complex<T> o) {
  complex<T> ao = a - o, bo = b - o;
  double angle =
      atan2(imag(bo), real(bo)) - atan2(imag(ao), real(ao));
  if (angle < 0) angle += 2 * M_PI;
  return angle;
}

template<class T>
double cross(complex<T> a, complex<T> b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

template<class T>
double dir(complex<T> p, complex<T> q, complex<T> r) {
  return real(p) * (imag(q) - imag(r)) +
         real(q) * (imag(r) - imag(p)) +
         real(r) * (imag(p) - imag(q));
}

template<class T>
bool ccw(complex<T> p, complex<T> q, complex<T> r) { return dir(p, q, r) > 0; }

template<class T>
bool cw(complex<T> p, complex<T> q, complex<T> r) { return dir(p, q, r) < 0; }

template<class T>
bool collinear(complex<T> p, complex<T> q, complex<T> r) { return abs(dir(p, q, r)) < EPS; }
