---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/articulationPoints.cc
    title: code/graphs/articulationPoints.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"tests/aoj/articulation_points.articulation_points.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
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
    \ \"code/graphs/articulationPoints.cc\"\nvi dfsNum, low;\nint dfsCounter = 0;\n\
    vvi adj;\nint artiDfs(int v, vi& a, int p = -1) {\n  dfsNum[v] = low[v] = dfsCounter++;\n\
    \  int children = 0;\n  bool aP = false;\n  for (int u : adj[v]) {\n    if (dfsNum[u]\
    \ == -1) {\n      ckmin(low[v], artiDfs(u, a, v));\n      if (low[u] >= dfsNum[v]\
    \ && p != -1 && !aP) {\n        a.pb(v);\n        aP = true;\n      }\n      children++;\n\
    \    } else if (u != p)\n      ckmin(low[v], dfsNum[u]);\n  }\n  if (p == -1 &&\
    \ children > 1) a.pb(v);\n  return low[v];\n}\nvi findArtiPoints() {\n  dfsNum.assign(SZ(adj),\
    \ -1);\n  low.assign(SZ(adj), -1);\n  dfsCounter = 0;\n  vi res;\n  F0R (v, SZ(adj))\n\
    \    if (dfsNum[v] == -1) artiDfs(v, res);\n  return res;\n}\n#line 4 \"tests/aoj/articulation_points.articulation_points.test.cpp\"\
    \nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E;\n\
    \  cin >> V >> E;\n\n  adj.resize(V);\n\n  F0R(i, E) {\n      int u, v;\n    \
    \  cin >> u >> v;\n      adj[u].eb(v);\n      adj[v].eb(u);\n  }\n\n  vi res =\
    \ findArtiPoints();\n  sort(ALL(res));\n  for(int i : res)\n      cout << i <<\
    \ endl;\n}\n\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include \"../../code/graphs/articulationPoints.cc\"\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.resize(V);\n\
    \n  F0R(i, E) {\n      int u, v;\n      cin >> u >> v;\n      adj[u].eb(v);\n\
    \      adj[v].eb(u);\n  }\n\n  vi res = findArtiPoints();\n  sort(ALL(res));\n\
    \  for(int i : res)\n      cout << i << endl;\n}\n\n\n\n\n"
  dependsOn:
  - code/graphs/articulationPoints.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/articulation_points.articulation_points.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 16:52:24+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/articulation_points.articulation_points.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/articulation_points.articulation_points.test.cpp
- /verify/tests/aoj/articulation_points.articulation_points.test.cpp.html
title: tests/aoj/articulation_points.articulation_points.test.cpp
---
