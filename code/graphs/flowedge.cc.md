---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: code/graphs/dinic.cc
    title: code/graphs/dinic.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/edmondsKarp.cc
    title: code/graphs/edmondsKarp.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/pushRelabel.cc
    title: code/graphs/pushRelabel.cc
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/dinic.maximum_flow.test.cpp
    title: tests/aoj/dinic.maximum_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/edmonds_karp.maximum_flow.test.cpp
    title: tests/aoj/edmonds_karp.maximum_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/push_relabel.maximum_flow.test.cpp
    title: tests/aoj/push_relabel.maximum_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/dinic.bipartitematching.test.cpp
    title: tests/yosupo/dinic.bipartitematching.test.cpp
  _isVerificationFailed: false
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
    \ << \"] \"\n#line 2 \"code/graphs/flowedge.cc\"\nstruct edge {\n  edge(int from,\
    \ int to, ll capacity, ll flow = 0)\n      : mfrom(from), mto(to), mcapacity(capacity),\
    \ mflow(flow) {}\n  int mfrom, mto;\n  ll mcapacity, mflow;\n  int other(int v)\
    \ { return v == mfrom ? mto : mfrom; }\n  ll capacity(int v) { return v == mfrom\
    \ ? mcapacity : 0; }\n  ll flow(int v) { return v == mfrom ? mflow : -mflow; }\n\
    \  void adjust(int v, ll amount) {\n    mflow += v == mfrom ? amount : -amount;\n\
    \  }\n};\nvector<edge> edges;\nvvi adj;\nvoid addEdge(int from, int to, ll c,\
    \ ll f = 0) {\n  edges.eb(from, to, c, f);\n  adj[from].pb(SZ(edges) - 1);\n \
    \ adj[to].pb(SZ(edges) - 1);\n}\nostream& operator<<(ostream& o, const edge& e)\
    \ {\n  return o << e.mfrom << \"-- \" << e.mflow << '/'\n           << e.mcapacity\
    \ << \" -->\" << e.mto;\n}\n"
  code: "#include \"../template.hh\"\nstruct edge {\n  edge(int from, int to, ll capacity,\
    \ ll flow = 0)\n      : mfrom(from), mto(to), mcapacity(capacity), mflow(flow)\
    \ {}\n  int mfrom, mto;\n  ll mcapacity, mflow;\n  int other(int v) { return v\
    \ == mfrom ? mto : mfrom; }\n  ll capacity(int v) { return v == mfrom ? mcapacity\
    \ : 0; }\n  ll flow(int v) { return v == mfrom ? mflow : -mflow; }\n  void adjust(int\
    \ v, ll amount) {\n    mflow += v == mfrom ? amount : -amount;\n  }\n};\nvector<edge>\
    \ edges;\nvvi adj;\nvoid addEdge(int from, int to, ll c, ll f = 0) {\n  edges.eb(from,\
    \ to, c, f);\n  adj[from].pb(SZ(edges) - 1);\n  adj[to].pb(SZ(edges) - 1);\n}\n\
    ostream& operator<<(ostream& o, const edge& e) {\n  return o << e.mfrom << \"\
    -- \" << e.mflow << '/'\n           << e.mcapacity << \" -->\" << e.mto;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/flowedge.cc
  requiredBy:
  - code/graphs/edmondsKarp.cc
  - code/graphs/dinic.cc
  - code/graphs/pushRelabel.cc
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/dinic.bipartitematching.test.cpp
  - tests/aoj/push_relabel.maximum_flow.test.cpp
  - tests/aoj/dinic.maximum_flow.test.cpp
  - tests/aoj/edmonds_karp.maximum_flow.test.cpp
documentation_of: code/graphs/flowedge.cc
layout: document
redirect_from:
- /library/code/graphs/flowedge.cc
- /library/code/graphs/flowedge.cc.html
title: code/graphs/flowedge.cc
---
