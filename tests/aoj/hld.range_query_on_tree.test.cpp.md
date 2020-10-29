---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/STIT.cc
    title: code/dataStructures/STIT.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/HLD.cc
    title: code/graphs/HLD.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"tests/aoj/hld.range_query_on_tree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\n\n#line\
    \ 1 \"code/template.cc\"\n// this line is here for a reason\n#include <bits/stdc++.h>\n\
    using namespace std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef\
    \ vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii>\
    \ vvii;\n#define fi first\n#define se second\n#define eb emplace_back\n#define\
    \ pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define endl '\\\
    n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n\
    #define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c);\
    \ ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T&\
    \ a, const T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\n\
    bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef\
    \ DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...)\
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/dataStructures/STIT.cc\"\
    \ntemplate<typename T, typename F>\nstruct ST {\n  using value_type = T;\n  using\
    \ merge_type = F; \n  const int n;\n  const T e;\n  F merge;\n  vector<T> data;\n\
    \  ST(int sz, T _e, F m) : n{sz}, e{_e}, merge{m}, data(2 * n, e) {}\n  void build()\
    \ {\n    for (int i = n - 1; i; --i)\n      data[i] = merge(data[i << 1], data[i\
    \ << 1 | 1]);\n  }\n  T query(int l, int r) {\n    T li = e, ri = e;\n    for\
    \ (l += n, r += n; l < r; r >>= 1, l >>= 1) {\n      if (l & 1) li = merge(li,\
    \ data[l++]);\n      if (r & 1) ri = merge(data[--r], ri);\n    }\n    return\
    \ merge(li, ri);\n  }\n  void update(int i, T val) {\n    for (data[i += n] =\
    \ val; i > 1; i >>= 1)\n      data[i >> 1] = merge(data[i & ~1], data[i | 1]);\n\
    \  }\n};\n#line 2 \"code/graphs/HLD.cc\"\ntemplate<typename T, typename F>\nstruct\
    \ HLD {\n  int n;\n  vi par, sz, height, in, pos;\n  vvi paths;\n  ST<T, F> st;\n\
    \  HLD(vvi& adj, const vector<T>& val,\n      T unit, F merge, int root = 0)\n\
    \    : n{SZ(adj)}, par(n), sz(n, 1), height(n), in(n), pos(n),\n      st{n, unit,\
    \ merge} {\n    dfssz(adj, root);\n    vi order;\n    dfsbuild(adj, root, order);\n\
    \    int j = 0;\n    for (auto it = order.crbegin(); it != order.crend(); ++it)\n\
    \      for (int v : paths[*it]) st.data[st.n + (pos[v] = j++)] = val[v];\n   \
    \ st.build();\n  }\n  int dfssz(vvi& adj, int v, int h = 0, int p = -1) {\n  \
    \  par[v] = p; height[v] = h;\n    for (int u : adj[v])\n      if (p != u) sz[v]\
    \ += dfssz(adj, u, h + 1, v);\n    return sz[v];\n  }\n  void dfsbuild(vvi& adj,\
    \ int v, vi& order, int p = -1, bool hvy = false) {\n    if (hvy) paths[in[v]\
    \ = in[p]].pb(v); \n    else {\n      in[v] = SZ(paths);\n      paths.pb({v});\n\
    \    }\n    int h = -1;\n    for (int u : adj[v])\n      if (p != u) {\n     \
    \   if (sz[u] > sz[v] / 2) h = u;\n        else dfsbuild(adj, u, order, v);\n\
    \      }\n    if (~h) dfsbuild(adj, h, order, v, true);\n    if (paths[in[v]][0]\
    \ == v) order.pb(in[v]);\n  }\n  void update(int v, T val) { st.update(pos[v],\
    \ val); }\n  T queryPath(int a, int b) {\n    T v = st.e;\n    while (in[a] !=\
    \ in[b]) {\n      if (height[paths[in[a]][0]] < height[paths[in[b]][0]]) swap(a,\
    \ b);\n      v = st.merge(v, st.query(pos[paths[in[a]][0]], pos[a] + 1));\n  \
    \    a = par[paths[in[a]][0]];\n    }\n    if (height[a] > height[b]) swap(a,\
    \ b);\n    return st.merge(v, st.query(pos[a], pos[b] + 1));\n  }\n  T querySubtree(int\
    \ v) {\n    return st.query(pos[v], pos[v] + sz[v]);\n  }\n};\n#line 4 \"tests/aoj/hld.range_query_on_tree.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int n;\n\
    \  cin >> n;\n\n  vvi adj(n);\n  F0R(i, n) {\n      int k;\n      cin >> k;\n\
    \      F0R(j, k) {\n          int c;\n          cin >> c;\n          adj[i].pb(c);\n\
    \          adj[c].pb(i);\n      }\n  }\n  \n  auto f = [](int a, int b) { return\
    \ a + b; };\n  HLD<int, decltype(f)> hld(adj, vi(n), 0, f);\n  \n  int q;\n  cin\
    \ >> q;\n  while(q--) {\n    bool b;\n    cin >> b;\n    if(!b) {\n      int v,\
    \ w;\n      cin >> v >> w;\n      int curr = hld.queryPath(v, v);\n      hld.update(v,\
    \ w + curr);\n    } else {\n      int u;\n      cin >> u;\n      cout << hld.queryPath(0,\
    \ u) << endl;\n    }\n  }\n}\n\n\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include \"../../code/graphs/HLD.cc\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \n  int n;\n  cin >> n;\n\n  vvi adj(n);\n  F0R(i, n) {\n      int k;\n      cin\
    \ >> k;\n      F0R(j, k) {\n          int c;\n          cin >> c;\n          adj[i].pb(c);\n\
    \          adj[c].pb(i);\n      }\n  }\n  \n  auto f = [](int a, int b) { return\
    \ a + b; };\n  HLD<int, decltype(f)> hld(adj, vi(n), 0, f);\n  \n  int q;\n  cin\
    \ >> q;\n  while(q--) {\n    bool b;\n    cin >> b;\n    if(!b) {\n      int v,\
    \ w;\n      cin >> v >> w;\n      int curr = hld.queryPath(v, v);\n      hld.update(v,\
    \ w + curr);\n    } else {\n      int u;\n      cin >> u;\n      cout << hld.queryPath(0,\
    \ u) << endl;\n    }\n  }\n}\n\n\n\n\n\n"
  dependsOn:
  - code/graphs/HLD.cc
  - code/dataStructures/STIT.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/hld.range_query_on_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 21:29:28+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/hld.range_query_on_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/hld.range_query_on_tree.test.cpp
- /verify/tests/aoj/hld.range_query_on_tree.test.cpp.html
title: tests/aoj/hld.range_query_on_tree.test.cpp
---
