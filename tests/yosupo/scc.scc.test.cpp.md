---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/scc.cc
    title: code/graphs/scc.cc
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"tests/yosupo/scc.scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
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
    \ \"code/graphs/scc.cc\"\nvvi adj;\nvi dfs_num, dfs_low, S;\nvector<bool> onStack;\n\
    int dfsCounter;\nvoid scc(int v, vvi& sccs) {\n  dfs_num[v] = dfs_low[v] = dfsCounter++;\n\
    \  S.push_back(v);\n  onStack[v] = true;\n  for (int u : adj[v]) {\n    if (dfs_num[u]\
    \ == -1) scc(u, sccs);\n    if (onStack[u]) ckmin(dfs_low[v], dfs_low[u]);\n \
    \ }\n  if (dfs_num[v] == dfs_low[v]) {\n    sccs.eb(); int u;\n    do {\n    \
    \  u = S.back();\n      S.pop_back();\n      onStack[u] = 0;\n      sccs.back().pb(u);\n\
    \    } while (u != v);\n  }\n}\nvvi scc() {\n    dfs_num.assign(SZ(adj), -1);\n\
    \    dfs_low.assign(SZ(adj), 0);\n    onStack.assign(SZ(adj), 0);\n    dfsCounter\
    \ = 0;\n    vvi sccs;\n    F0R (i, SZ(adj))\n\tif (!~dfs_num[i]) scc(i, sccs);\n\
    \    return sccs;\n}\n#line 4 \"tests/yosupo/scc.scc.test.cpp\"\n\nint main()\
    \ {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int n, m;\n  cin >> n\
    \ >> m;\n\n  adj.assign(n, vi());\n  F0R(i, m) {\n    int u, v;\n    cin >> u\
    \ >> v;\n    adj[u].pb(v);\n  }\n\n  vvi comp = scc();\n  cout << SZ(comp) <<\
    \ endl;\n  for(int i = SZ(comp) - 1; ~i; --i) {\n      cout << SZ(comp[i]) <<\
    \ ' ';\n      for(int x : comp[i])\n          cout << x << ' ';\n      cout <<\
    \ endl;\n  }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../code/graphs/scc.cc\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int n, m;\n\
    \  cin >> n >> m;\n\n  adj.assign(n, vi());\n  F0R(i, m) {\n    int u, v;\n  \
    \  cin >> u >> v;\n    adj[u].pb(v);\n  }\n\n  vvi comp = scc();\n  cout << SZ(comp)\
    \ << endl;\n  for(int i = SZ(comp) - 1; ~i; --i) {\n      cout << SZ(comp[i])\
    \ << ' ';\n      for(int x : comp[i])\n          cout << x << ' ';\n      cout\
    \ << endl;\n  }\n}\n\n"
  dependsOn:
  - code/graphs/scc.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/scc.scc.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 09:01:05+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/scc.scc.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/scc.scc.test.cpp
- /verify/tests/yosupo/scc.scc.test.cpp.html
title: tests/yosupo/scc.scc.test.cpp
---
