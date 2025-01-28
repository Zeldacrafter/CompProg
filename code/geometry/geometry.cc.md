---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy:
  - icon: ':warning:'
    path: code/geometry/convexHull.cc
    title: code/geometry/convexHull.cc
  - icon: ':heavy_check_mark:'
    path: code/geometry/polygon.cc
    title: code/geometry/polygon.cc
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/ccw.counter_clockwise.test.cpp
    title: tests/aoj/ccw.counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/polygon_area.test.cpp
    title: tests/aoj/polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/polygon_contains_point.test.cpp
    title: tests/aoj/polygon_contains_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/polygon_convex.test.cpp
    title: tests/aoj/polygon_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/template.cc\"\n// this line is here for a reason\n\
    #include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef\
    \ vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n\
    #define eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a,\
    \ b, c) for (auto a = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\n\
    template <typename T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true\
    \ : false; }\ntemplate <typename T>\nbool ckmax(T& a, const T& b) { return a <\
    \ b ? a = b, true : false; }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define\
    \ dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__)\
    \ << \"] \"\n#line 2 \"code/geometry/geometry.cc\"\n#define xx real()\n#define\
    \ yy imag()\nconst double EPS = 1e-9;\nconst double INF = numeric_limits<double>::max();\n\
    using pt = complex<double>;\nstruct Line {\n  double a, b, c;\n};  // ax + by\
    \ + c = 0\ndouble dot(pt a, pt b) { return a.xx * b.xx + a.yy * b.yy; }\ndouble\
    \ cross(pt a, pt b) { return a.xx * b.yy - a.yy * b.xx; }\ndouble dir(pt a, pt\
    \ b, pt c) { return cross(b - a, c - a); }\nbool cw(pt a, pt b, pt c) { return\
    \ dir(a, b, c) < 0; }\nbool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }\n\
    bool collinear(pt a, pt b, pt c) { return abs(dir(a, b, c)) < EPS; }\n// Angle\
    \ between a and b with o as origin (ccw).\n// Return value in [0, 2PI)\ndouble\
    \ angle(pt a, pt b) {\n  double ang = arg(a) - arg(b);\n  return ang < 0 ? ang\
    \ + 2 * M_PI : ang;\n}\ndouble angle(pt a, pt b, pt o) { return angle(b - o, a\
    \ - o); }\n// Theta in radiens\npt rotate(pt a, double theta) { return a * polar(1.0,\
    \ theta); }\nLine ptToLine(pt p1, pt p2) {\n  if (abs(real(p1) - real(p2)) < EPS)\
    \ {\n    return {1.0, 0.0, -real(p1)};\n  } else {\n    double a = -(imag(p1)\
    \ - imag(p2)) / (real(p1) - real(p2)),\n           c = -(a * real(p1)) - imag(p1);\n\
    \    return {a, 1.0, c};\n  }\n}\nbool areParallel(Line l1, Line l2) {\n  return\
    \ abs(l1.a - l2.a) < EPS && abs(l1.b - l2.b) < EPS;\n}\nbool areSame(Line l1,\
    \ Line l2) {\n  return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;\n}\npt intersectPt(Line\
    \ l1, Line l2) {\n  // Does not handle if same or parrallel\n  if (areParallel(l1,\
    \ l2)) return pt(-INF, -INF);\n  double x =\n      (l2.b * l1.c - l1.b * l2.c)\
    \ / (l2.a * l1.b - l1.a * l2.b);\n  double y;\n  if (abs(l1.b) < EPS)\n    y =\
    \ -(l1.a * x + l1.c);\n  else\n    y = -(l2.a * x + l2.c);\n  return pt(x, y);\n\
    }\ndouble distToLine(pt p, pt a, pt b, bool segment = false) {\n  pt ap = p -\
    \ a, ab = b - a;\n  double u = dot(ap, ab) / (abs(ab) * abs(ab));\n  if (segment)\
    \ {\n    if (u < 0.0) return abs(p - a);  // a is closest\n    if (u > 1.0) return\
    \ abs(p - b);  // b is closest\n  }\n  return abs(p - a - ab * u);      // closest\
    \ is in segment.\n}\n"
  code: "#include \"../template.hh\"\n#define xx real()\n#define yy imag()\nconst\
    \ double EPS = 1e-9;\nconst double INF = numeric_limits<double>::max();\nusing\
    \ pt = complex<double>;\nstruct Line {\n  double a, b, c;\n};  // ax + by + c\
    \ = 0\ndouble dot(pt a, pt b) { return a.xx * b.xx + a.yy * b.yy; }\ndouble cross(pt\
    \ a, pt b) { return a.xx * b.yy - a.yy * b.xx; }\ndouble dir(pt a, pt b, pt c)\
    \ { return cross(b - a, c - a); }\nbool cw(pt a, pt b, pt c) { return dir(a, b,\
    \ c) < 0; }\nbool ccw(pt a, pt b, pt c) { return dir(a, b, c) > 0; }\nbool collinear(pt\
    \ a, pt b, pt c) { return abs(dir(a, b, c)) < EPS; }\n// Angle between a and b\
    \ with o as origin (ccw).\n// Return value in [0, 2PI)\ndouble angle(pt a, pt\
    \ b) {\n  double ang = arg(a) - arg(b);\n  return ang < 0 ? ang + 2 * M_PI : ang;\n\
    }\ndouble angle(pt a, pt b, pt o) { return angle(b - o, a - o); }\n// Theta in\
    \ radiens\npt rotate(pt a, double theta) { return a * polar(1.0, theta); }\nLine\
    \ ptToLine(pt p1, pt p2) {\n  if (abs(real(p1) - real(p2)) < EPS) {\n    return\
    \ {1.0, 0.0, -real(p1)};\n  } else {\n    double a = -(imag(p1) - imag(p2)) /\
    \ (real(p1) - real(p2)),\n           c = -(a * real(p1)) - imag(p1);\n    return\
    \ {a, 1.0, c};\n  }\n}\nbool areParallel(Line l1, Line l2) {\n  return abs(l1.a\
    \ - l2.a) < EPS && abs(l1.b - l2.b) < EPS;\n}\nbool areSame(Line l1, Line l2)\
    \ {\n  return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;\n}\npt intersectPt(Line\
    \ l1, Line l2) {\n  // Does not handle if same or parrallel\n  if (areParallel(l1,\
    \ l2)) return pt(-INF, -INF);\n  double x =\n      (l2.b * l1.c - l1.b * l2.c)\
    \ / (l2.a * l1.b - l1.a * l2.b);\n  double y;\n  if (abs(l1.b) < EPS)\n    y =\
    \ -(l1.a * x + l1.c);\n  else\n    y = -(l2.a * x + l2.c);\n  return pt(x, y);\n\
    }\ndouble distToLine(pt p, pt a, pt b, bool segment = false) {\n  pt ap = p -\
    \ a, ab = b - a;\n  double u = dot(ap, ab) / (abs(ab) * abs(ab));\n  if (segment)\
    \ {\n    if (u < 0.0) return abs(p - a);  // a is closest\n    if (u > 1.0) return\
    \ abs(p - b);  // b is closest\n  }\n  return abs(p - a - ab * u);      // closest\
    \ is in segment.\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/geometry/geometry.cc
  requiredBy:
  - code/geometry/polygon.cc
  - code/geometry/convexHull.cc
  timestamp: '2023-12-28 00:27:15+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/polygon_convex.test.cpp
  - tests/aoj/polygon_area.test.cpp
  - tests/aoj/ccw.counter_clockwise.test.cpp
  - tests/aoj/polygon_contains_point.test.cpp
documentation_of: code/geometry/geometry.cc
layout: document
redirect_from:
- /library/code/geometry/geometry.cc
- /library/code/geometry/geometry.cc.html
title: code/geometry/geometry.cc
---
