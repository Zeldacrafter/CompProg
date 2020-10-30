---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/geometry/geometry.cc
    title: code/geometry/geometry.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
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
    \ is in segment.\n}\n#line 2 \"code/geometry/convexHull.cc\"\n// careful with\
    \ inputs for n < 2\nvector<pt> convexHull(vector<pt>& pts) {\n  int n = SZ(pts);\n\
    \  sort(ALL(pts),\n       [](pt a, pt b) { return mp(a.xx, a.yy) < mp(b.xx, b.yy);\
    \ });\n  vector<pt> up, down;\n  up.eb(pts[0]); down.eb(pts[0]);\n  FOR (i, 1,\
    \ n) {\n    // for colinear poins change ccw->!cw & cw->!ccw\n    if (i == n -\
    \ 1 || ccw(pts[0], pts[n - 1], pts[i])) {\n      while (SZ(up) > 1 &&\n      \
    \       ccw(up[SZ(up) - 2], up[SZ(up) - 1], pts[i]))\n        up.pop_back();\n\
    \      up.eb(pts[i]);\n    }\n    if (i == n - 1 || cw(pts[0], pts[n - 1], pts[i]))\
    \ {\n      while (SZ(down) > 1 &&\n             cw(down[SZ(down) - 2], down[SZ(down)\
    \ - 1], pts[i]))\n        down.pop_back();\n      down.eb(pts[i]);\n    }\n  }\n\
    \  vector<pt> ans(up);\n  ans.insert(ans.end(), 1 + RALL(down));\n  return ans;\n\
    }\n"
  code: "#include \"geometry.cc\"\n// careful with inputs for n < 2\nvector<pt> convexHull(vector<pt>&\
    \ pts) {\n  int n = SZ(pts);\n  sort(ALL(pts),\n       [](pt a, pt b) { return\
    \ mp(a.xx, a.yy) < mp(b.xx, b.yy); });\n  vector<pt> up, down;\n  up.eb(pts[0]);\
    \ down.eb(pts[0]);\n  FOR (i, 1, n) {\n    // for colinear poins change ccw->!cw\
    \ & cw->!ccw\n    if (i == n - 1 || ccw(pts[0], pts[n - 1], pts[i])) {\n     \
    \ while (SZ(up) > 1 &&\n             ccw(up[SZ(up) - 2], up[SZ(up) - 1], pts[i]))\n\
    \        up.pop_back();\n      up.eb(pts[i]);\n    }\n    if (i == n - 1 || cw(pts[0],\
    \ pts[n - 1], pts[i])) {\n      while (SZ(down) > 1 &&\n             cw(down[SZ(down)\
    \ - 2], down[SZ(down) - 1], pts[i]))\n        down.pop_back();\n      down.eb(pts[i]);\n\
    \    }\n  }\n  vector<pt> ans(up);\n  ans.insert(ans.end(), 1 + RALL(down));\n\
    \  return ans;\n}\n"
  dependsOn:
  - code/geometry/geometry.cc
  - code/template.cc
  isVerificationFile: false
  path: code/geometry/convexHull.cc
  requiredBy: []
  timestamp: '2020-10-30 13:45:04+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/geometry/convexHull.cc
layout: document
redirect_from:
- /library/code/geometry/convexHull.cc
- /library/code/geometry/convexHull.cc.html
title: code/geometry/convexHull.cc
---
