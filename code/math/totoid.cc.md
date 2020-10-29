---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/totoid.eulers_phi_function.test.cpp
    title: tests/aoj/totoid.eulers_phi_function.test.cpp
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
    \ << \"] \"\n#line 2 \"code/math/totoid.cc\"\nint phi(int n) {\n    int result\
    \ = n;\n    for (int i = 2; i * i <= n; i++) {\n        if(n % i == 0) {\n   \
    \         while(n % i == 0) n /= i;\n            result -= result / i;\n     \
    \   }\n    }\n    if(n > 1) result -= result / n;\n    return result;\n}\n"
  code: "#include \"../template.hh\"\nint phi(int n) {\n    int result = n;\n    for\
    \ (int i = 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            while(n\
    \ % i == 0) n /= i;\n            result -= result / i;\n        }\n    }\n   \
    \ if(n > 1) result -= result / n;\n    return result;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/math/totoid.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/totoid.eulers_phi_function.test.cpp
documentation_of: code/math/totoid.cc
layout: document
redirect_from:
- /library/code/math/totoid.cc
- /library/code/math/totoid.cc.html
title: code/math/totoid.cc
---
