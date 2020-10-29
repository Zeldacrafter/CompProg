---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/bridges.cc
    title: code/graphs/bridges.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"tests/aoj/brides.brides.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
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
    \ \"code/graphs/bridges.cc\"\nvvi adj;\nvi dfsNum, low;\nint dfsCounter = 0;\n\
    int bridgeDfs(int v, vii& b, int p = -1) {\n  dfsNum[v] = low[v] = dfsCounter++;\n\
    \  for (int u : adj[v]) {\n    if (dfsNum[u] == -1) {\n      ckmin(low[v], bridgeDfs(u,\
    \ b, v));\n      if (low[u] > dfsNum[v]) b.eb(v, u);\n    } else if (u != p)\n\
    \      ckmin(low[v], dfsNum[u]);\n  }\n  return low[v];\n}\nvii findBridges()\
    \ {\n  vii bridges;\n  dfsNum.assign(SZ(adj), -1);\n  low.assign(SZ(adj), -1);\n\
    \  F0R (v, SZ(adj))\n    if (dfsNum[v] == -1) bridgeDfs(v, bridges);\n  return\
    \ bridges;\n}\n#line 4 \"tests/aoj/brides.brides.test.cpp\"\n\nint main() {\n\
    \  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >>\
    \ E;\n\n  adj.resize(V);\n\n  F0R(i, E) {\n      int u, v;\n      cin >> u >>\
    \ v;\n      adj[u].eb(v);\n      adj[v].eb(u);\n  }\n\n  vii res = findBridges();\n\
    \  for(auto& [a, b] : res) if(a > b) swap(a, b);\n  sort(ALL(res));\n  for(auto\
    \ [a, b] : res)\n      cout << a << ' ' << b << endl;\n}\n\n\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include \"../../code/graphs/bridges.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.resize(V);\n\
    \n  F0R(i, E) {\n      int u, v;\n      cin >> u >> v;\n      adj[u].eb(v);\n\
    \      adj[v].eb(u);\n  }\n\n  vii res = findBridges();\n  for(auto& [a, b] :\
    \ res) if(a > b) swap(a, b);\n  sort(ALL(res));\n  for(auto [a, b] : res)\n  \
    \    cout << a << ' ' << b << endl;\n}\n\n\n\n\n\n"
  dependsOn:
  - code/graphs/bridges.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/brides.brides.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 16:58:23+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/brides.brides.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/brides.brides.test.cpp
- /verify/tests/aoj/brides.brides.test.cpp.html
title: tests/aoj/brides.brides.test.cpp
---
