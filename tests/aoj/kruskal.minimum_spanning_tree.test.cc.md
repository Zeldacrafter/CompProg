---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/DSU.cc
    title: code/dataStructures/DSU.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/kruskal.cc
    title: code/graphs/kruskal.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"tests/aoj/kruskal.minimum_spanning_tree.test.cc\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
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
    \ \"code/dataStructures/DSU.cc\"\nstruct DSU {\n  DSU(int size) : msize(size),\
    \ data(size, -1) {}\n  bool sameSet(int a, int b) { return find(a) == find(b);\
    \ }\n  int find(int x) {\n    return data[x] < 0 ? x : data[x] = find(data[x]);\n\
    \  }\n  bool join(int a, int b) {\n    a = find(a), b = find(b);\n    if (a ==\
    \ b) return false;\n    if (data[a] > data[b]) swap(a, b);\n    data[a] += data[b],\
    \ data[b] = a;\n    return --msize, true;\n  }\n  int size() { return msize; }\n\
    \  int size(int a) { return -data[find(a)]; }\n  int msize;\n  vi data;\n};\n\
    #line 2 \"code/graphs/kruskal.cc\"\nvector<tuple<double, int, int>> edges;\nint\
    \ V; // bool indicates if MST could be found / graph is connected\ntuple<bool,\
    \ double, vi> kruskal() {\n  sort(ALL(edges)); DSU dsu(V); vi mst;\n  double weigth\
    \ = 0;\n  for (int i = 0; SZ(dsu) > 1 && i < SZ(edges); ++i) {\n    auto [d, a,\
    \ b] = edges[i];\n    if (dsu.join(a, b)) mst.pb(i), weigth += d;\n  }\n  return\
    \ mt(SZ(dsu) == 1, weigth, mst);\n}\n#line 4 \"tests/aoj/kruskal.minimum_spanning_tree.test.cc\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int E;\n\
    \  cin >> V >> E;\n\n  F0R(i, E) {\n      int u, v;\n      double w;\n      cin\
    \ >> u >> v >> w;\n      edges.eb(w, u, v);\n  }\n\n  cout << (ll)get<1>(kruskal())\
    \ << endl;\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../code/graphs/kruskal.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int E;\n  cin >> V >> E;\n\n  F0R(i, E)\
    \ {\n      int u, v;\n      double w;\n      cin >> u >> v >> w;\n      edges.eb(w,\
    \ u, v);\n  }\n\n  cout << (ll)get<1>(kruskal()) << endl;\n}\n\n"
  dependsOn:
  - code/graphs/kruskal.cc
  - code/dataStructures/DSU.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/kruskal.minimum_spanning_tree.test.cc
  requiredBy: []
  timestamp: '2020-10-29 09:38:34+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/kruskal.minimum_spanning_tree.test.cc
layout: document
redirect_from:
- /verify/tests/aoj/kruskal.minimum_spanning_tree.test.cc
- /verify/tests/aoj/kruskal.minimum_spanning_tree.test.cc.html
title: tests/aoj/kruskal.minimum_spanning_tree.test.cc
---
