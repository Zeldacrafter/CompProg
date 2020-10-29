---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/SPT.cc
    title: code/dataStructures/SPT.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/LCA.cc
    title: code/graphs/LCA.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/yosupo/sparse_table.lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"code/template.cc\"\n//\
    \ this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef\
    \ vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define\
    \ fi first\n#define se second\n#define eb emplace_back\n#define pb push_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define endl '\\n'\n#define ALL(x)\
    \ (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x)\
    \ (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))\n\
    #define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\nbool ckmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef DEBUG\n#define\
    \ DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__\
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/dataStructures/SPT.cc\"\n\
    template <typename T, typename F>\nstruct SPT {\n  vector<vector<T>> d;\n  F f;\n\
    \  SPT (int n, F _f) : d(32 - __builtin_clz(n), vector<T>(n)), f{_f} {}\n  SPT\
    \ (const vector<T>& v, F _f) : SPT(SZ(v), _f) {\n    d[0] = v;\n    build();\n\
    \  }\n  void build() {\n    for (int j = 1; (1 << j) <= SZ(d[0]); ++j) {\n   \
    \   for (int i = 0; i + (1 << j) <= SZ(d[0]); ++i) {\n        d[j][i] = f(d[j\
    \ - 1][i], d[j - 1][i + (1 << (j - 1))]);\n      }\n    }\n  }\n  T query(int\
    \ l, int r) { // [l, r)\n    int k = 31 - __builtin_clz(r - l);\n    return f(d[k][l],\
    \ d[k][r - (1 << k)]);\n  }\n};\n\n#line 2 \"code/graphs/LCA.cc\"\nstruct LCA\
    \ {\n  vi height, first;\n  SPT<int, function<int(int, int)>> spt;\n  LCA(vvi&\
    \ adj, int root = 0) : height(SZ(adj), -1), first(SZ(adj), -1),\n      spt(2 *\
    \ SZ(adj) - 1, [self = this](int a, int b) {\n        return self->height[a] <\
    \ self->height[b] ? a : b;\n      }) {\n    int idx = 0;\n    dfs(adj, root, idx);\n\
    \    spt.build();\n  }\n  void dfs(vvi& adj, int v, int& idx, int h = 0) {\n \
    \   first[v] = idx;\n    spt.d[0][idx++] = v;\n    height[v] = h;\n    for (int\
    \ u : adj[v]) if (first[u] == -1) {\n      dfs(adj, u, idx, h + 1);\n      spt.d[0][idx++]\
    \ = v;\n    }\n  }\n  int query(int a, int b) {\n    ii m = minmax(first[a], first[b]);\n\
    \    return spt.query(m.fi, m.se);\n  }\n};\n#line 4 \"tests/yosupo/sparse_table.lca.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios_base::sync_with_stdio(0);\n\n    int\
    \ n, q; cin >> n >> q;\n\n    vvi adj(n);\n    FOR (i, 1, n) {\n        int u;\
    \ cin >> u;\n        adj[i].pb(u);\n        adj[u].pb(i);\n    }\n\n    LCA lca(adj);\n\
    \    while(q--) {\n        int u, v; cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../code/graphs/LCA.cc\"\
    \n\nint main() {\n    cin.tie(0);\n    ios_base::sync_with_stdio(0);\n\n    int\
    \ n, q; cin >> n >> q;\n\n    vvi adj(n);\n    FOR (i, 1, n) {\n        int u;\
    \ cin >> u;\n        adj[i].pb(u);\n        adj[u].pb(i);\n    }\n\n    LCA lca(adj);\n\
    \    while(q--) {\n        int u, v; cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << endl;\n    }\n}\n"
  dependsOn:
  - code/graphs/LCA.cc
  - code/dataStructures/SPT.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/sparse_table.lca.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 23:44:21+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/sparse_table.lca.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/sparse_table.lca.test.cpp
- /verify/tests/yosupo/sparse_table.lca.test.cpp.html
title: tests/yosupo/sparse_table.lca.test.cpp
---
