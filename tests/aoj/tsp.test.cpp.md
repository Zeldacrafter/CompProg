---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dynamicProgramming/tsp.cc
    title: code/dynamicProgramming/tsp.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"tests/aoj/tsp.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
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
    \ \"code/dynamicProgramming/tsp.cc\"\nconst int INF = 1e9;\nvvi dp, adj; // adjacency\
    \ matrix\nint tsp_calc(int pos, int start, int mask) {\n  if ((1 << SZ(adj)) -\
    \ 1 == mask) return adj[pos][start];\n  if (dp[pos][mask] != -1) return dp[pos][mask];\n\
    \  int minV = INF;\n  F0R (i, SZ(adj))\n    if (i != pos && !(mask & (1 << i)))\n\
    \      ckmin(minV, adj[pos][i] + tsp_calc(i, start, mask | (1 << i)));\n  return\
    \ dp[pos][mask] = minV;\n}\nint tsp(int start = 0) {\n  dp.assign(SZ(adj), vi(1\
    \ << SZ(adj), -1));\n  F0R(i, SZ(adj)) ckmin(adj[i][i], 0);\n  return tsp_calc(start,\
    \ start, 1 << start);\n}\n#line 4 \"tests/aoj/tsp.test.cpp\"\n\nint main() {\n\
    \  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int N, E;\n  cin >> N >>\
    \ E;\n\n  adj.assign(N, vi(N, INF));\n  F0R(i, E) {\n      int s, t, d;\n    \
    \  cin >> s >> t >> d;\n      adj[s][t] = d;\n  }\n\n  int res = tsp();\n  cout\
    \ << (res == INF ? -1 : res) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#include \"../../code/dynamicProgramming/tsp.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int N, E;\n  cin >> N >> E;\n\n  adj.assign(N,\
    \ vi(N, INF));\n  F0R(i, E) {\n      int s, t, d;\n      cin >> s >> t >> d;\n\
    \      adj[s][t] = d;\n  }\n\n  int res = tsp();\n  cout << (res == INF ? -1 :\
    \ res) << endl;\n}\n"
  dependsOn:
  - code/dynamicProgramming/tsp.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/tsp.test.cpp
  requiredBy: []
  timestamp: '2020-10-30 00:46:21+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/tsp.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/tsp.test.cpp
- /verify/tests/aoj/tsp.test.cpp.html
title: tests/aoj/tsp.test.cpp
---
