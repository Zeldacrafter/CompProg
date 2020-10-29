---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: code/graphs/topoSort.cc
    title: code/graphs/topoSort.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"tests/aoj/toposort.topological_sort.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
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
    \ \"code/graphs/topoSort.cc\"\nvvi adj;\nvi in;  // in degree for every node\n\
    vi toposort() {\n  vi q; // Result saved in q\n  F0R (i, SZ(adj))\n    if (!in[i])\
    \ q.pb(i);\n  F0R (i, SZ(q))\n    for (int v : adj[q[i]])\n      if (!--in[v])\
    \ q.pb(v);\n  return q;\n}\n#line 4 \"tests/aoj/toposort.topological_sort.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E;\n\
    \  cin >> V >> E;\n\n  adj.resize(V);\n  in.assign(V, 0);\n\n  F0R(i, E) {\n \
    \     int u, v;\n      cin >> u >> v;\n      adj[u].pb(v);\n      in[v]++;\n \
    \ }\n\n  vi sorting = toposort();\n  for(int x : sorting) \n      cout << x <<\
    \ endl;\n}\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include \"../../code/graphs/topoSort.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.resize(V);\n\
    \  in.assign(V, 0);\n\n  F0R(i, E) {\n      int u, v;\n      cin >> u >> v;\n\
    \      adj[u].pb(v);\n      in[v]++;\n  }\n\n  vi sorting = toposort();\n  for(int\
    \ x : sorting) \n      cout << x << endl;\n}\n\n\n\n"
  dependsOn:
  - code/graphs/topoSort.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/toposort.topological_sort.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 09:51:38+01:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/aoj/toposort.topological_sort.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/toposort.topological_sort.test.cpp
- /verify/tests/aoj/toposort.topological_sort.test.cpp.html
title: tests/aoj/toposort.topological_sort.test.cpp
---
