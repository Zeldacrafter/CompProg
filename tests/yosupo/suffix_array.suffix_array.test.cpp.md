---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/strings/SA.cc
    title: code/strings/SA.cc
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
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"tests/yosupo/suffix_array.suffix_array.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#line 1 \"code/template.cc\"\
    \n// this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n\
    #define fi first\n#define se second\n#define eb emplace_back\n#define pb push_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define endl '\\n'\n#define ALL(x)\
    \ (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x)\
    \ (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))\n\
    #define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\nbool ckmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef DEBUG\n#define\
    \ DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__\
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/strings/SA.cc\"\nvii SA_ns,\
    \ SA_bs;\nusing vit = vi::iterator;\ntemplate<int B = 'a', int S = 26, int N =\
    \ 3>\nstruct SA {\n  vi sa, rank, lcp;\n  SA(const string& s) {\n    SA_bs.resize(max(S,\
    \ SZ(s)) + 2);\n    SA_ns.resize(max(S, SZ(s)) + 2);\n    vi ra(SZ(s) + 1 + N);\n\
    \    F0R (i, SZ(s)) ra[i] = s[i] - B + 2;\n    ra[SZ(s)] = 1;\n    sa = build(ra);\n\
    \  }\n  void buildRank() {\n    rank.resize(SZ(sa));\n    F0R (i, SZ(sa)) rank[sa[i]]\
    \ = i;\n  }\n  void buildLcp(const string& s) {\n    if(rank.empty()) buildRank();\n\
    \    lcp.resize(SZ(sa) - 1);\n    int k = 0;\n    F0R (i, SZ(sa)) {\n      if\
    \ (rank[i] == SZ(sa) - 1) {\n        k = 0; continue;\n      }\n      for (int\
    \ j = sa[rank[i] + 1]; max(i, j) + k < SZ(s) && s[i + k] == s[j + k]; ++k);\n\
    \      lcp[rank[i]] = k;\n      if (k) --k;\n    }\n  }\n  vi build(const vi&\
    \ prefRank) {\n    int n = SZ(prefRank) - N;\n    int offset = n / N + !!(n %\
    \ N);\n    vi arr; arr.reserve(n);\n    array<int, N> offs;\n    F0R (j, N) {\n\
    \      offs[j] = SZ(arr) - offset;\n      for (int i = j; i < n; i += N) arr.pb(i);\n\
    \    }\n    rsort(offset + ALL(arr), N, [&](int i, int it) { return prefRank[i\
    \ + it]; });\n    vi ra(n - offset + N);\n    int r = 1;\n    FOR (i, offset,\
    \ n) {\n      ra[offs[arr[i] % N] + arr[i] / N] = r;\n      if (i + 1 < n)\n \
    \       F0R (j, N)\n          if (prefRank[arr[i] + j] != prefRank[arr[i + 1]\
    \ + j]) {\n            r++; break;\n          }\n    }\n    if (r < n - offset)\
    \ {\n      vi got(build(ra));\n      F0R (i, SZ(got)) ra[got[i]] = i;\n      FOR\
    \ (j, 1, N) for (int i = 0; j + i * N < n; ++i)\n        arr[offset + ra[offs[j]\
    \ + i]] = j + i * N;\n    }\n    rsort(arr.begin(), arr.begin() + offset, 2, [&](int\
    \ i, int it) {\n      return it ? ra[offs[(i + 1) % N] + (i + 1) / N] : prefRank[i];\n\
    \    });\n    vi tmp(arr.begin(), arr.begin() + offset);\n    int o = 0, m = offset,\
    \ i = 0;\n    while (o < offset && m < n) {\n      int c = 0;\n      for (int\
    \ k = 0; !c; ++k) {\n        int a = tmp[o] + k, b = arr[m] + k;\n        c =\
    \ (a % N && b % N) \n          ? cmp(ra[offs[a % N] + a / N], ra[offs[b % N] +\
    \ b / N]) \n            : cmp(prefRank[a], prefRank[b]);\n      }\n      arr[i++]\
    \ = c < 0 ? tmp[o++] : arr[m++];\n    }\n    while (o < offset) arr[i++] = tmp[o++];\n\
    \    return arr;\n  }\n  static inline int cmp(int a, int b) { return (a > b)\
    \ - (a < b); }\n  template<typename F>\n  static void rsort(vit vb, vit ve, int\
    \ iters, F bf) {\n    for (int d = iters - 1; ~d; --d) {\n      int mx = 0;\n\
    \      F0R (i, distance(vb, ve)) {\n        int b = bf(*(vb + i), d);\n      \
    \  for (; mx <= b; ++mx) SA_bs[mx].fi = -1;\n        if (SA_bs[b].fi == -1) SA_bs[b]\
    \ = mp(i, i);\n        SA_ns[SA_bs[b].se].se = i;\n        SA_ns[i] = mp(*(vb\
    \ + i), -1);\n        SA_bs[b].se = i;\n      }\n      vit j = vb;\n      F0R\
    \ (i, mx)\n        for (int it = SA_bs[i].fi; ~it; it = SA_ns[it].se, ++j)\n \
    \         *j = SA_ns[it].fi;\n    }\n  }\n};\n#line 4 \"tests/yosupo/suffix_array.suffix_array.test.cpp\"\
    \n\nint main() {\n  ios_base::sync_with_stdio(0);\n  cin.tie(0);\n\n  string s;\
    \ cin >> s;\n  SA sa(s);\n  FOR (i, 1, SZ(sa.sa)) cout << sa.sa[i] << ' ';\n \
    \ cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../code/strings/SA.cc\"\n\nint main() {\n  ios_base::sync_with_stdio(0);\n\
    \  cin.tie(0);\n\n  string s; cin >> s;\n  SA sa(s);\n  FOR (i, 1, SZ(sa.sa))\
    \ cout << sa.sa[i] << ' ';\n  cout << endl;\n}\n"
  dependsOn:
  - code/strings/SA.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/suffix_array.suffix_array.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:36:12+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/suffix_array.suffix_array.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/suffix_array.suffix_array.test.cpp
- /verify/tests/yosupo/suffix_array.suffix_array.test.cpp.html
title: tests/yosupo/suffix_array.suffix_array.test.cpp
---
