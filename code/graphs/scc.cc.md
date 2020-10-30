---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/scc.scc.test.cpp
    title: tests/yosupo/scc.scc.test.cpp
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
    \ << \"] \"\n#line 2 \"code/graphs/scc.cc\"\nvvi adj;\nvi dfs_num, dfs_low, S;\n\
    vector<bool> onStack;\nint dfsCounter;\nvoid scc(int v, vvi& sccs) {\n  dfs_num[v]\
    \ = dfs_low[v] = dfsCounter++;\n  S.push_back(v);\n  onStack[v] = true;\n  for\
    \ (int u : adj[v]) {\n    if (dfs_num[u] == -1) scc(u, sccs);\n    if (onStack[u])\
    \ ckmin(dfs_low[v], dfs_low[u]);\n  }\n  if (dfs_num[v] == dfs_low[v]) {\n   \
    \ sccs.eb(); int u;\n    do {\n      u = S.back();\n      S.pop_back();\n    \
    \  onStack[u] = 0;\n      sccs.back().pb(u);\n    } while (u != v);\n  }\n}\n\
    vvi scc() {\n    dfs_num.assign(SZ(adj), -1);\n    dfs_low.assign(SZ(adj), 0);\n\
    \    onStack.assign(SZ(adj), 0);\n    dfsCounter = 0;\n    vvi sccs;\n    F0R\
    \ (i, SZ(adj))\n\tif (!~dfs_num[i]) scc(i, sccs);\n    return sccs;\n}\n"
  code: "#include \"../template.hh\"\nvvi adj;\nvi dfs_num, dfs_low, S;\nvector<bool>\
    \ onStack;\nint dfsCounter;\nvoid scc(int v, vvi& sccs) {\n  dfs_num[v] = dfs_low[v]\
    \ = dfsCounter++;\n  S.push_back(v);\n  onStack[v] = true;\n  for (int u : adj[v])\
    \ {\n    if (dfs_num[u] == -1) scc(u, sccs);\n    if (onStack[u]) ckmin(dfs_low[v],\
    \ dfs_low[u]);\n  }\n  if (dfs_num[v] == dfs_low[v]) {\n    sccs.eb(); int u;\n\
    \    do {\n      u = S.back();\n      S.pop_back();\n      onStack[u] = 0;\n \
    \     sccs.back().pb(u);\n    } while (u != v);\n  }\n}\nvvi scc() {\n    dfs_num.assign(SZ(adj),\
    \ -1);\n    dfs_low.assign(SZ(adj), 0);\n    onStack.assign(SZ(adj), 0);\n   \
    \ dfsCounter = 0;\n    vvi sccs;\n    F0R (i, SZ(adj))\n\tif (!~dfs_num[i]) scc(i,\
    \ sccs);\n    return sccs;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/scc.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/scc.scc.test.cpp
documentation_of: code/graphs/scc.cc
layout: document
redirect_from:
- /library/code/graphs/scc.cc
- /library/code/graphs/scc.cc.html
title: code/graphs/scc.cc
---
