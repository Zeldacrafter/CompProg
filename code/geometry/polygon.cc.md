---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/geometry/geometry.cc
    title: code/geometry/geometry.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/polygon_area.test.cpp
    title: tests/aoj/polygon_area.test.cpp
  - icon: ':x:'
    path: tests/aoj/polygon_contains_point.test.cpp
    title: tests/aoj/polygon_contains_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/polygon_convex.test.cpp
    title: tests/aoj/polygon_convex.test.cpp
  _pathExtension: cc
  _verificationStatusIcon: ':question:'
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
    \ - imag(p2)) / (real(p1) - real(p2)),\n           c = -(a * real(p1)) - imag(p2);\n\
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
    \ is in segment.\n}\n#line 2 \"code/geometry/polygon.cc\"\nbool inTriangle(pt\
    \ a, pt b, pt c, pt p) {\n  return\n    abs(-abs(dir(a, b, c)) + abs(dir(a, b,\
    \ p))\n        + abs(dir(a, p, c)) + abs(dir(p, b, c))) < EPS;\n}\n// poly sorted\
    \ in clockwise direction.\n// returns true if point is on edge of poly.\nbool\
    \ inPolygon(const vector<pt>& poly, pt p) {\n  int l = 1, r = SZ(poly) - 2;\n\
    \  while (l < r) {\n    int mid = (l + r) / 2;\n    if (cw(poly[0], poly[mid],\
    \ p))\n      l = mid + 1;\n    else\n      r = mid;\n  }\n  return inTriangle(poly[0],\
    \ poly[l], poly[l - 1], p);\n}\ndouble area(const vector<pt>& p) {\n  double res\
    \ = 0.0;\n  F0R (i, SZ(p))\n    res += cross(p[i], p[(i + 1) % SZ(p)]);\n  return\
    \ abs(res) / 2;\n}\nbool isConvex(const vector<pt>& p) {\n  if (SZ(p) < 3) return\
    \ false;\n  bool isLeft = ccw(p[0], p[1], p[2]) || collinear(p[0], p[1], p[2]),\n\
    \      convex = true;\n  F0R (i, SZ(p))\n    convex &= isLeft == (ccw(p[i], p[(i\
    \ + 1) % SZ(p)], p[(i + 2) % SZ(p)])\n                     || collinear(p[i],\
    \ p[(i + 1) % SZ(p)], p[(i + 2) % SZ(p)]));\n  return convex;\n}\n"
  code: "#include \"geometry.cc\"\nbool inTriangle(pt a, pt b, pt c, pt p) {\n  return\n\
    \    abs(-abs(dir(a, b, c)) + abs(dir(a, b, p))\n        + abs(dir(a, p, c)) +\
    \ abs(dir(p, b, c))) < EPS;\n}\n// poly sorted in clockwise direction.\n// returns\
    \ true if point is on edge of poly.\nbool inPolygon(const vector<pt>& poly, pt\
    \ p) {\n  int l = 1, r = SZ(poly) - 2;\n  while (l < r) {\n    int mid = (l +\
    \ r) / 2;\n    if (cw(poly[0], poly[mid], p))\n      l = mid + 1;\n    else\n\
    \      r = mid;\n  }\n  return inTriangle(poly[0], poly[l], poly[l - 1], p);\n\
    }\ndouble area(const vector<pt>& p) {\n  double res = 0.0;\n  F0R (i, SZ(p))\n\
    \    res += cross(p[i], p[(i + 1) % SZ(p)]);\n  return abs(res) / 2;\n}\nbool\
    \ isConvex(const vector<pt>& p) {\n  if (SZ(p) < 3) return false;\n  bool isLeft\
    \ = ccw(p[0], p[1], p[2]) || collinear(p[0], p[1], p[2]),\n      convex = true;\n\
    \  F0R (i, SZ(p))\n    convex &= isLeft == (ccw(p[i], p[(i + 1) % SZ(p)], p[(i\
    \ + 2) % SZ(p)])\n                     || collinear(p[i], p[(i + 1) % SZ(p)],\
    \ p[(i + 2) % SZ(p)]));\n  return convex;\n}\n"
  dependsOn:
  - code/geometry/geometry.cc
  - code/template.cc
  isVerificationFile: false
  path: code/geometry/polygon.cc
  requiredBy: []
  timestamp: '2020-10-30 10:23:31+01:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/aoj/polygon_convex.test.cpp
  - tests/aoj/polygon_contains_point.test.cpp
  - tests/aoj/polygon_area.test.cpp
documentation_of: code/geometry/polygon.cc
layout: document
redirect_from:
- /library/code/geometry/polygon.cc
- /library/code/geometry/polygon.cc.html
title: code/geometry/polygon.cc
---
