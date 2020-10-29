---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/lcs.longest_common_subsequence.test.cpp
    title: tests/aoj/lcs.longest_common_subsequence.test.cpp
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
    \ << \"] \"\n#line 2 \"code/dynamicProgramming/lcs.cc\"\nint lcs(const string&\
    \ s, const string& t) {\n  int n = SZ(s), m = SZ(t);\n  vvi dp(n + 1, vi(m + 1,\
    \ 0));\n  dp[n - 1][m - 1] = s[n - 1] == t[m - 1];\n  for (int i = n - 2; ~i;\
    \ --i)\n    dp[i][m - 1] = s[i] == t[m - 1] ? 1 : dp[i + 1][m - 1];\n  for (int\
    \ i = m - 2; ~i; --i)\n    dp[n - 1][i] = s[n - 1] == t[i] ? 1 : dp[n - 1][i +\
    \ 1];\n  for (int i = n - 2; ~i; --i)\n    for (int j = m - 2; ~j; --j)\n    \
    \  dp[i][j] = max({dp[i + 1][j + 1] + (s[i] == t[j]),\n                      dp[i\
    \ + 1][j], dp[i][j + 1]});\n  return dp[0][0];\n}\n"
  code: "#include \"../template.hh\"\nint lcs(const string& s, const string& t) {\n\
    \  int n = SZ(s), m = SZ(t);\n  vvi dp(n + 1, vi(m + 1, 0));\n  dp[n - 1][m -\
    \ 1] = s[n - 1] == t[m - 1];\n  for (int i = n - 2; ~i; --i)\n    dp[i][m - 1]\
    \ = s[i] == t[m - 1] ? 1 : dp[i + 1][m - 1];\n  for (int i = m - 2; ~i; --i)\n\
    \    dp[n - 1][i] = s[n - 1] == t[i] ? 1 : dp[n - 1][i + 1];\n  for (int i = n\
    \ - 2; ~i; --i)\n    for (int j = m - 2; ~j; --j)\n      dp[i][j] = max({dp[i\
    \ + 1][j + 1] + (s[i] == t[j]),\n                      dp[i + 1][j], dp[i][j +\
    \ 1]});\n  return dp[0][0];\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dynamicProgramming/lcs.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/lcs.longest_common_subsequence.test.cpp
documentation_of: code/dynamicProgramming/lcs.cc
layout: document
redirect_from:
- /library/code/dynamicProgramming/lcs.cc
- /library/code/dynamicProgramming/lcs.cc.html
title: code/dynamicProgramming/lcs.cc
---
