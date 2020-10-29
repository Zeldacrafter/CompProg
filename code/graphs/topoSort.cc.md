---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/aoj/toposort.topological_sort.test.cpp
    title: tests/aoj/toposort.topological_sort.test.cpp
  _pathExtension: cc
  _verificationStatusIcon: ':x:'
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
    \ << \"] \"\n#line 2 \"code/graphs/topoSort.cc\"\nvvi adj;\nvi in;  // in degree\
    \ for every node\nvi toposort() {\n  vi q; // Result saved in q\n  F0R (i, SZ(adj))\n\
    \    if (!in[i]) q.pb(i);\n  F0R (i, SZ(q))\n    for (int v : adj[q[i]])\n   \
    \   if (!--in[v]) q.pb(v);\n  return q;\n}\n"
  code: "#include \"../template.hh\"\nvvi adj;\nvi in;  // in degree for every node\n\
    vi toposort() {\n  vi q; // Result saved in q\n  F0R (i, SZ(adj))\n    if (!in[i])\
    \ q.pb(i);\n  F0R (i, SZ(q))\n    for (int v : adj[q[i]])\n      if (!--in[v])\
    \ q.pb(v);\n  return q;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/topoSort.cc
  requiredBy: []
  timestamp: '2020-10-29 09:51:38+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/aoj/toposort.topological_sort.test.cpp
documentation_of: code/graphs/topoSort.cc
layout: document
redirect_from:
- /library/code/graphs/topoSort.cc
- /library/code/graphs/topoSort.cc.html
title: code/graphs/topoSort.cc
---
