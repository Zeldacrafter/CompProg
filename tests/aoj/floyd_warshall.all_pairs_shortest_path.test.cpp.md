---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/floydWarshall.cc
    title: code/graphs/floydWarshall.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
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
    \ \"code/graphs/floydWarshall.cc\"\nconst ll INF = 1e18;\nvector<vector<ll>> adj;\
    \  // adjacency matrix\nbool negCycle = false;\nvoid floydWarshall() {\n  F0R\
    \ (k, SZ(adj)) F0R (i, SZ(adj)) F0R (j, SZ(adj))\n    if(adj[i][k] != INF && adj[k][j]\
    \ != INF)\n      ckmin(adj[i][j], adj[i][k] + adj[k][j]);\n  F0R (k, SZ(adj))\
    \ if(adj[k][k] < 0) negCycle = true;\n}\n#line 4 \"tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E;\n\
    \  cin >> V >> E;\n\n  adj.assign(V, vector<ll>(V, INF));\n\n  F0R(i, E) {\n \
    \     int u, v, d;\n      cin >> u >> v >> d;\n      ckmin(adj[u][v], (ll)d);\n\
    \  }\n\n  F0R(i, V) adj[i][i] = 0;\n  floydWarshall();\n\n  if(negCycle) {\n \
    \     cout << \"NEGATIVE CYCLE\\n\";\n  } else {\n      F0R(i, V) {\n        F0R(j,\
    \ V) {\n          if(j) cout << ' ';\n          if(adj[i][j] == INF)\n       \
    \     cout << \"INF\";\n          else\n            cout << adj[i][j];\n     \
    \   }\n        cout << endl;\n      }\n  }\n}\n\n\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include \"../../code/graphs/floydWarshall.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.assign(V,\
    \ vector<ll>(V, INF));\n\n  F0R(i, E) {\n      int u, v, d;\n      cin >> u >>\
    \ v >> d;\n      ckmin(adj[u][v], (ll)d);\n  }\n\n  F0R(i, V) adj[i][i] = 0;\n\
    \  floydWarshall();\n\n  if(negCycle) {\n      cout << \"NEGATIVE CYCLE\\n\";\n\
    \  } else {\n      F0R(i, V) {\n        F0R(j, V) {\n          if(j) cout << '\
    \ ';\n          if(adj[i][j] == INF)\n            cout << \"INF\";\n         \
    \ else\n            cout << adj[i][j];\n        }\n        cout << endl;\n   \
    \   }\n  }\n}\n\n\n\n\n\n"
  dependsOn:
  - code/graphs/floydWarshall.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 16:39:06+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
- /verify/tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp.html
title: tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
---
