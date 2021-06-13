---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dynamicProgramming/lis.cc
    title: code/dynamicProgramming/lis.cc
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"tests/aoj/lis.longest_increasing_subsequence.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
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
    \ \"code/dynamicProgramming/lis.cc\"\nconst int inf = 1e9;\n\nint lis(const vi&\
    \ a) {\n  vi dp(SZ(a) + 1, inf);\n  dp[0] = -inf;\n  F0R(i, SZ(a)) {\n    int\
    \ ind = upper_bound(ALL(dp), a[i]) - dp.begin();\n    if(dp[ind - 1] < a[i] &&\
    \ a[i] < dp[ind])\n      dp[ind] = a[i];\n  }\n  return lower_bound(ALL(dp), inf)\
    \ - dp.begin() - 1;\n}\n#line 4 \"tests/aoj/lis.longest_increasing_subsequence.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int n;\n\
    \  cin >> n;\n  vi a(n);\n  F0R(i, n) cin >> a[i];\n\n  cout << lis(a) << endl;\n\
    }\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include \"../../code/dynamicProgramming/lis.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int n;\n  cin >> n;\n  vi a(n);\n  F0R(i,\
    \ n) cin >> a[i];\n\n  cout << lis(a) << endl;\n}\n\n\n"
  dependsOn:
  - code/dynamicProgramming/lis.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/lis.longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 22:52:12+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/lis.longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/lis.longest_increasing_subsequence.test.cpp
- /verify/tests/aoj/lis.longest_increasing_subsequence.test.cpp.html
title: tests/aoj/lis.longest_increasing_subsequence.test.cpp
---
