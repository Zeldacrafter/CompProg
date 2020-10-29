---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/math/extendedEuclid.cc
    title: code/math/extendedEuclid.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"tests/aoj/extended_euclid.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\n\n#line 1\
    \ \"code/template.cc\"\n// this line is here for a reason\n#include <bits/stdc++.h>\n\
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
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/math/extendedEuclid.cc\"\
    \nll gcd(ll x, ll y, ll& a, ll& b) {\n  if (y) {\n    ll res = gcd(y, x % y, b,\
    \ a);\n    return b -= x / y * a, res; \n  }\n  return a = 1, b = 0, x;\n}\n#line\
    \ 4 \"tests/aoj/extended_euclid.test.cpp\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \n  ll a, b, x, y;\n  cin >> a >> b;\n  gcd(a, b, x, y);\n  cout << x << ' ' <<\
    \ y << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include \"../../code/math/extendedEuclid.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  ll a, b, x, y;\n  cin >> a >> b;\n  gcd(a,\
    \ b, x, y);\n  cout << x << ' ' << y << endl;\n}\n"
  dependsOn:
  - code/math/extendedEuclid.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/extended_euclid.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 22:40:23+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/extended_euclid.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/extended_euclid.test.cpp
- /verify/tests/aoj/extended_euclid.test.cpp.html
title: tests/aoj/extended_euclid.test.cpp
---
