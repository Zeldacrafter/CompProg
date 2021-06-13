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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"tests/aoj/ccw.counter_clockwise.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\n\n#line\
    \ 1 \"code/template.cc\"\n// this line is here for a reason\n#include <bits/stdc++.h>\n\
    using namespace std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef\
    \ vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii>\
    \ vvii;\n#define fi first\n#define se second\n#define eb emplace_back\n#define\
    \ pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define endl '\\\
    n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n\
    #define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c);\
    \ ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T&\
    \ a, const T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\n\
    bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef\
    \ DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...)\
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/geometry/geometry.cc\"\
    \n#define xx real()\n#define yy imag()\nconst double EPS = 1e-9;\nconst double\
    \ INF = numeric_limits<double>::max();\nusing pt = complex<double>;\nstruct Line\
    \ {\n  double a, b, c;\n};  // ax + by + c = 0\ndouble dot(pt a, pt b) { return\
    \ a.xx * b.xx + a.yy * b.yy; }\ndouble cross(pt a, pt b) { return a.xx * b.yy\
    \ - a.yy * b.xx; }\ndouble dir(pt a, pt b, pt c) { return cross(b - a, c - a);\
    \ }\nbool cw(pt a, pt b, pt c) { return dir(a, b, c) < 0; }\nbool ccw(pt a, pt\
    \ b, pt c) { return dir(a, b, c) > 0; }\nbool collinear(pt a, pt b, pt c) { return\
    \ abs(dir(a, b, c)) < EPS; }\n// Angle between a and b with o as origin (ccw).\n\
    // Return value in [0, 2PI)\ndouble angle(pt a, pt b) {\n  double ang = arg(a)\
    \ - arg(b);\n  return ang < 0 ? ang + 2 * M_PI : ang;\n}\ndouble angle(pt a, pt\
    \ b, pt o) { return angle(b - o, a - o); }\n// Theta in radiens\npt rotate(pt\
    \ a, double theta) { return a * polar(1.0, theta); }\nLine ptToLine(pt p1, pt\
    \ p2) {\n  if (abs(real(p1) - real(p2)) < EPS) {\n    return {1.0, 0.0, -real(p1)};\n\
    \  } else {\n    double a = -(imag(p1) - imag(p2)) / (real(p1) - real(p2)),\n\
    \           c = -(a * real(p1)) - imag(p2);\n    return {a, 1.0, c};\n  }\n}\n\
    bool areParallel(Line l1, Line l2) {\n  return abs(l1.a - l2.a) < EPS && abs(l1.b\
    \ - l2.b) < EPS;\n}\nbool areSame(Line l1, Line l2) {\n  return areParallel(l1,\
    \ l2) && abs(l1.c - l2.c) < EPS;\n}\npt intersectPt(Line l1, Line l2) {\n  //\
    \ Does not handle if same or parrallel\n  if (areParallel(l1, l2)) return pt(-INF,\
    \ -INF);\n  double x =\n      (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a\
    \ * l2.b);\n  double y;\n  if (abs(l1.b) < EPS)\n    y = -(l1.a * x + l1.c);\n\
    \  else\n    y = -(l2.a * x + l2.c);\n  return pt(x, y);\n}\ndouble distToLine(pt\
    \ p, pt a, pt b, bool segment = false) {\n  pt ap = p - a, ab = b - a;\n  double\
    \ u = dot(ap, ab) / (abs(ab) * abs(ab));\n  if (segment) {\n    if (u < 0.0) return\
    \ abs(p - a);  // a is closest\n    if (u > 1.0) return abs(p - b);  // b is closest\n\
    \  }\n  return abs(p - a - ab * u);      // closest is in segment.\n}\n#line 4\
    \ \"tests/aoj/ccw.counter_clockwise.test.cpp\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  double x0, y0, x1, y1;\n  int q;\n  cin\
    \ >> x0 >> y0 >> x1 >> y1 >> q;\n  pt p0(x0, y0), p1(x1, y1);\n\n  while(q--)\
    \ {\n    int x2, y2;\n    cin >> x2 >> y2;\n    pt p2(x2, y2);\n\n    if(ccw(p0,\
    \ p1, p2))\n        cout << \"COUNTER_CLOCKWISE\\n\";\n    else if(cw(p0, p1,\
    \ p2))\n        cout << \"CLOCKWISE\\n\";\n    else if(abs(p0 - p2) < EPS || abs(p1\
    \ - p2) < EPS || (abs(p0 - p2) < abs(p0 - p1) && abs(p1 - p2) < abs(p1 - p0)))\n\
    \        cout << \"ON_SEGMENT\\n\";\n    else if(abs(p1 - p2) > abs(p0 - p1) &&\
    \ abs(p1 - p2) > abs(p0 - p2))\n        cout << \"ONLINE_BACK\\n\";\n    else\n\
    \        cout << \"ONLINE_FRONT\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include \"../../code/geometry/geometry.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  double x0, y0, x1, y1;\n  int q;\n  cin\
    \ >> x0 >> y0 >> x1 >> y1 >> q;\n  pt p0(x0, y0), p1(x1, y1);\n\n  while(q--)\
    \ {\n    int x2, y2;\n    cin >> x2 >> y2;\n    pt p2(x2, y2);\n\n    if(ccw(p0,\
    \ p1, p2))\n        cout << \"COUNTER_CLOCKWISE\\n\";\n    else if(cw(p0, p1,\
    \ p2))\n        cout << \"CLOCKWISE\\n\";\n    else if(abs(p0 - p2) < EPS || abs(p1\
    \ - p2) < EPS || (abs(p0 - p2) < abs(p0 - p1) && abs(p1 - p2) < abs(p1 - p0)))\n\
    \        cout << \"ON_SEGMENT\\n\";\n    else if(abs(p1 - p2) > abs(p0 - p1) &&\
    \ abs(p1 - p2) > abs(p0 - p2))\n        cout << \"ONLINE_BACK\\n\";\n    else\n\
    \        cout << \"ONLINE_FRONT\\n\";\n  }\n}\n"
  dependsOn:
  - code/geometry/geometry.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/ccw.counter_clockwise.test.cpp
  requiredBy: []
  timestamp: '2020-10-30 09:22:11+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/ccw.counter_clockwise.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/ccw.counter_clockwise.test.cpp
- /verify/tests/aoj/ccw.counter_clockwise.test.cpp.html
title: tests/aoj/ccw.counter_clockwise.test.cpp
---
