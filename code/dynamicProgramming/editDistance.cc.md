---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/edit_distance.test.cpp
    title: tests/aoj/edit_distance.test.cpp
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
    \ << \"] \"\n#line 2 \"code/dynamicProgramming/editDistance.cc\"\nconst int inf\
    \ = 1e9;\n\nint editDistance(const string& a, const string& b) {\n  vvi dp(SZ(a)\
    \ + 1, vi(SZ(b) + 1, inf));\n  F0R(i, SZ(a) + 1) {\n    F0R(j, SZ(b) + 1) {\n\
    \      if(!i) dp[i][j] = j;\n      else if(!j) dp[i][j] = i;\n      else {\n \
    \       dp[i][j] = 1 + min({dp[i - 1][j - 1],\n                            dp[i][j\
    \ - 1], dp[i - 1][j]});\n        if(a[i - 1] == b[j - 1]) ckmin(dp[i][j], dp[i\
    \ - 1][j - 1]);\n      }\n    }\n  }\n  return dp[SZ(a)][SZ(b)];\n}\n"
  code: "#include \"../template.hh\"\nconst int inf = 1e9;\n\nint editDistance(const\
    \ string& a, const string& b) {\n  vvi dp(SZ(a) + 1, vi(SZ(b) + 1, inf));\n  F0R(i,\
    \ SZ(a) + 1) {\n    F0R(j, SZ(b) + 1) {\n      if(!i) dp[i][j] = j;\n      else\
    \ if(!j) dp[i][j] = i;\n      else {\n        dp[i][j] = 1 + min({dp[i - 1][j\
    \ - 1],\n                            dp[i][j - 1], dp[i - 1][j]});\n        if(a[i\
    \ - 1] == b[j - 1]) ckmin(dp[i][j], dp[i - 1][j - 1]);\n      }\n    }\n  }\n\
    \  return dp[SZ(a)][SZ(b)];\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dynamicProgramming/editDistance.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/edit_distance.test.cpp
documentation_of: code/dynamicProgramming/editDistance.cc
layout: document
redirect_from:
- /library/code/dynamicProgramming/editDistance.cc
- /library/code/dynamicProgramming/editDistance.cc.html
title: code/dynamicProgramming/editDistance.cc
---
