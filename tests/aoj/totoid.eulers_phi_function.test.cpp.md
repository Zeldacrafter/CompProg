---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/math/totoid.cc
    title: code/math/totoid.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"tests/aoj/totoid.eulers_phi_function.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#line 1 \"code/template.cc\"\n// this line is here for a reason\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef pair<int,\
    \ int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi>\
    \ vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n#define\
    \ eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(),\
    \ (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a\
    \ = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename\
    \ T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }\ntemplate\
    \ <typename T>\nbool ckmax(T& a, const T& b) { return a < b ? a = b, true : false;\
    \ }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define\
    \ dvar(...) \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2\
    \ \"code/math/totoid.cc\"\nint phi(int n) {\n    int result = n;\n    for (int\
    \ i = 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            while(n % i\
    \ == 0) n /= i;\n            result -= result / i;\n        }\n    }\n    if(n\
    \ > 1) result -= result / n;\n    return result;\n}\n#line 4 \"tests/aoj/totoid.eulers_phi_function.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  ll n;\n\
    \  cin >> n;\n  cout << phi(n) << endl;\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include \"../../code/math/totoid.cc\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \n  ll n;\n  cin >> n;\n  cout << phi(n) << endl;\n}\n\n"
  dependsOn:
  - code/math/totoid.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/totoid.eulers_phi_function.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 22:43:21+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/totoid.eulers_phi_function.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/totoid.eulers_phi_function.test.cpp
- /verify/tests/aoj/totoid.eulers_phi_function.test.cpp.html
title: tests/aoj/totoid.eulers_phi_function.test.cpp
---
