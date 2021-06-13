---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dynamicProgramming/editDistance.cc
    title: code/dynamicProgramming/editDistance.cc
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"tests/aoj/edit_distance.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
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
    \ \"code/dynamicProgramming/editDistance.cc\"\nconst int inf = 1e9;\n\nint editDistance(const\
    \ string& a, const string& b) {\n  vvi dp(SZ(a) + 1, vi(SZ(b) + 1, inf));\n  F0R(i,\
    \ SZ(a) + 1) {\n    F0R(j, SZ(b) + 1) {\n      if(!i) dp[i][j] = j;\n      else\
    \ if(!j) dp[i][j] = i;\n      else {\n        dp[i][j] = 1 + min({dp[i - 1][j\
    \ - 1],\n                            dp[i][j - 1], dp[i - 1][j]});\n        if(a[i\
    \ - 1] == b[j - 1]) ckmin(dp[i][j], dp[i - 1][j - 1]);\n      }\n    }\n  }\n\
    \  return dp[SZ(a)][SZ(b)];\n}\n#line 4 \"tests/aoj/edit_distance.test.cpp\"\n\
    \nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  string s1,\
    \ s2;\n  cin >> s1 >> s2;\n  cout << editDistance(s1, s2) << endl;\n}\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include \"../../code/dynamicProgramming/editDistance.cc\"\n\nint main() {\n\
    \  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  string s1, s2;\n  cin >>\
    \ s1 >> s2;\n  cout << editDistance(s1, s2) << endl;\n}\n\n\n"
  dependsOn:
  - code/dynamicProgramming/editDistance.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/edit_distance.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 22:54:37+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/edit_distance.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/edit_distance.test.cpp
- /verify/tests/aoj/edit_distance.test.cpp.html
title: tests/aoj/edit_distance.test.cpp
---
